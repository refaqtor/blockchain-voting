#include "peer.hpp"
#include "processor.hpp"
#include "communication.hpp"
#include "rsa.hpp"
//#include "sha1.h"
#include <openssl/sha.h>
#include <openssl/rsa.h>

using namespace std;

struct comm_thread_args {
	synchronized_queue<transaction*>* tq;
	synchronized_queue<block*>* bq;
	synchronized_queue<std::string>* peerq;
};

struct processing_thread_args {
	synchronized_queue<transaction*>* tq;
	synchronized_queue<block*>* bq;
	synchronized_queue<std::string>* peerq;
};

static int leading_zeros(unsigned char* buf, size_t n) {
	int lz = 0;
	for (int i = 0; i < n; i++) {
		if (buf[i] == 0) {
			lz += 2;
		}
		else if ((buf[i] >> 4) == 0) {
			++lz;
			break;
		}
		else {
			break;
		}
	}
	return lz;
}

void* comm_thread (void* arg) {
	comm_thread_args* ctap = (comm_thread_args *) arg;
	cout << "Hello from comm thread\n";
	return NULL;
}

void* processing_thread(void* arg) {
	processing_thread_args* ptap = (processing_thread_args *) arg;
	cout << "Hello from processing thread\n";

	blockchain bc(ptap->tq);
	bc.chain_length = 0;

	// When this variable is true, we have a full set of
	// transactions to try to make a block with, otherwise we do not, so we are waiting
	// on that
	bool quotafull = false;
	block* new_block = new block;

	// This is an example of how code will be encrypted and decrypted. 

	// Create a message to encrypt
	char data[256] = "This is the message to encrypt/decrypt. If you see this, it works!"; 
	// Create buffers that will store the encrypted and decrypted results.
	unsigned char encrypted[4098];
	unsigned char decrypted[4098];

	// Encrypt and store in "encrypted". Get the encrypted_length
	//int encrypted_length = private_encrypt((unsigned char *) data,
	//		strlen(data), "private.pem", encrypted);
	// Decrypt and store in "decrypted"
	//public_decrypt(encrypted, encrypted_length, "public.pem", decrypted);
	// print message to stdout. It should match what is in data above.
	//cout << decrypted << endl;
	
	bool docontinue = false;

	while(true) {
		docontinue = false;

		// Call pop_nonblocking. If not null, add the block to the blockchain, clear progress
		// on new block, add everything from the block to the set
		block* b = ptap->bq->pop_nonblocking();
		if (b) {
			// TODO: clear progress somehow
			switch(bc.check_block_validity(b)) {
				case OK:
					bc.add_block(b);
					break;
				case PREV_BLOCK_NONMATCH:
					// Check if this block number is higher than ours, in which
					// case we need to accept that chain instead of ours
					if (b->block_number > bc.get_head_block()->block_number) {
						// Do important shit here
						// send requests for missing blocks, and align them to current
						// blockchain
						// O(n^2) algorithm for alignment
						// maybe this should set maxind to 0
						bc.repair_blockchain(b);
						quotafull = false;
						new_block->max_ind = 0;
						// TODO: merkle tree
						for (int i = 0; i < new_block->max_ind; ++i) {
							ptap->tq->push(new_block->transaction_array[i]);
						}
						
						new_block = new block;
					}
					else {
						docontinue = true;
					}
					break;
				case TRANSACTION_INVALID:
					docontinue = true;
					break;
			}
		}

		if (docontinue)
			continue;

		// Get a transaction from the transaction queue.
		transaction* new_trans;
		if (quotafull == false)
			new_trans = ptap->tq->pop();
		
		// Check if already in the block chain (via the unordered set). If so, throw it out.
		if (quotafull == false &&
				bc.voted.find(new_trans->sender_public_key) != bc.voted.end()) {
			continue;
		}

		if (quotafull == false) {
			new_block->transaction_array[new_block->max_ind] = new_trans;
			++new_block->max_ind;
			if (new_block->max_ind == 64) {
				quotafull = true;
			}
		}

		// try to create a block NUM_MAGIC_TO_TRY times.
		// advantages the property that there is always useful work to do
		// while waiting to receive a new block
		if (quotafull) {
			for (int throwaway = 0; throwaway < NUM_MAGIC_TO_TRY; ++throwaway) {
				// if successful, set quotafull back to false
				// else do another iteration
				++new_block->magic;
				new_block->calculate_finhash();
				if (leading_zeros((unsigned char *)new_block->finhash, 20) >= NUM_LEADING_ZEROS) {
					quotafull = false;
					new_block->max_ind = 0;
					bc.add_block(new_block);
					new_block = new block;
					break;
				}
			}
		}

	}


	return NULL;
}

int main () {

	const char str[] = "Original String";
  unsigned char hash[SHA_DIGEST_LENGTH]; // == 20

  SHA1((const unsigned char*)str, sizeof(str) - 1, hash);

  for (int i = 0; i < 20; ++i)
		printf("%02X", hash[i]);
	printf("\n");

	pthread_t comm_t;
	pthread_t processing_t;

	unsigned char x[5];
	x[0] = 1;
	x[1] = 0;
	x[2] = 249;
	x[3] = 248;
	x[4] = 0;

	cout << "Leading zeros: " << leading_zeros(x, 5) << endl;

	synchronized_queue<transaction*> tq = synchronized_queue<transaction*>();
	tq.init();

	synchronized_queue<block*> bq = synchronized_queue<block*>();
	bq.init();

	synchronized_queue<std::string> peerq = synchronized_queue<std::string>();
	peerq.init();

	comm_thread_args cta;
	cta.tq = &tq;
	cta.bq = &bq;
	cta.peerq = &peerq;

	processing_thread_args pta;
	pta.tq = &tq;
	pta.bq = &bq;
	pta.peerq = &peerq;

	pthread_create(&comm_t, NULL, comm_thread, &cta);
	pthread_create(&processing_t, NULL, processing_thread, &pta);

	pthread_join(comm_t, NULL);
	pthread_join(processing_t, NULL);

	return 0;
}




