#ifndef __PEER_H__
#define __PEER_H__
#include <openssl/sha.h>
#include "processor.hpp"
#include "rsa.hpp"
#include "client.hpp"
#include "server.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <queue>
#include <openssl/rsa.h>
#include <chrono>
#include <thread>

// This number defines how many iterations to try to find a new block
// before recalling bootsrap_peers(), which we should do to ensure
// we have a group of live peers.
#define BOOTSTRAP_RETRY 50

unsigned char* SHA1(const unsigned char* s, size_t size, unsigned char* md);

/* 
	This struct defines the arguments that the communcations thread
	will receieve from the master thread
*/
struct comm_thread_args {
	synchronized_queue<transaction*>* tq;
	synchronized_queue<block*>* bq;
	synchronized_queue<std::string*>* peerq;
	blockchain* bc;
	Client* client;
};

/* 
	This struct defines the arguments that processor thread will receive
	from the master thread
*/
struct processing_thread_args {
	synchronized_queue<transaction*>* tq;
	synchronized_queue<block*>* bq;
	synchronized_queue<std::string*>* peerq;
	blockchain* bc;
	Client* client;
};

#endif
