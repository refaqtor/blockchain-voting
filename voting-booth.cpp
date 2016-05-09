#include "voting-booth.hpp"




int main (int argc, char** argv) {
	if (argc != 5) {
		std::cout << "Usage: ./voting-booth your-ip-address:port first-peer-address:port publickeyfile vote";
		return 1;
	}

	std::string own_address(argv[1]);
	std::string first_peer(argv[2]);

	std::ifstream t(argv[3]);
	std::string publickey((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());

	std::cout << publickey << std::endl;

	// Client* client = new Client("VotingBoothAddress", first_peer);
	// client->bootstrapPeers();

	// transaction* t = new transaction;
}
