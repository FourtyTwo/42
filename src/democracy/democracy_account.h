#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*

    democracy_account.h - Code that handles the creation of new democracy accounts to vote. Democracy accounts are derived from
    your wallet address. To vote on protocol, network, or general elections, you must have at least above or equal to
    300 - 500 h/s on the network.
    
    Note: democracy_account will mostly be used to handle management of your own democracy account within the 42 wallet client.
    
    TODO - Need better unique voting verification than just minimum hashrate requirement

*/

class democracy_account {
    public:
    // methods
    bool load_democracy_account(); // Loads democracy account from file
    bool verify_democracy_account(std::string address); // Verifys democracy account
    std::string return_democracy_key_for_account(std::string address); // Returns democracy account derived from inputted address
    std::string sign_message_with_democracy_key(std::string message); // test function
    bool sign_vote_for_election(democracy_state vote_pool); // Method for using your democracy account for voting
    bool sign_vote_for_edict(democracy_state vote_pool);
    
    private:
    // variables
    std::string democracy_key;
};
