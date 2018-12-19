#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "dns_util/ddns_object.h"  // ddns data object
#include "dns_util/ddns_db.h"      // ddns db object - TODO: Will migrate to LMDB in the future rather than just storing info via rudimentary means

/*

The ddns_util class is basically an object with all the utilities needed for creating ddns names, verifying ddns names
currently in the blockchain, pushing a ddns name into the blockchain etc etc

*/

class ddns_util {
  public:
  // methods
  bool load_dns_from_db(); // Should be ran at startup to put all DNS information into a vector or something so that it can be accessed quickly
  int return_ddns_count(); // Returns the current count of all DNS names in the blockchain 
  std::vector<dns_object> return_all_known_dns(); // Returns all known DDNS names in the blockchain into a vector
  ddns_object return_dns_info_by_hash(std::string hash); // Returns DDNS object by DDNS hash
  ddns_object return_dns_info_by_name(std::string ddns_name); // Returns DDNS object by DDNS name
  std::string return_dns_ip_by_name(std::string ddns_name); // Return DDNS IP by name
  std::string return_dns_ip_by_hash(std::string hash); // Returns DDNS IP by hash
  bool verify_ddns_list(); // Verifys current DDNS list to make sure there isn't any invalid DDNS
  bool verify_ddns_transaction(std::string ddns_tx); // Verifies a certain DDNS transaction - TODO - DNS_TRANSACTION CLASS or edited version of base tx class
  bool push_ddns_to_blockchain(ddns_object ddns_obj); // Verifies and pushes DDNS object to blockchain if valid
  std::vector<dns_object> scan_blockchain_for_ddns_outputs(BlockchainDB db); // Scans blockchain for DDNS transactions and adds them to the list
  
  
  
  private:
  // variables
  int current_ddns_count; // Int of all current dns names in blockchain
  bool all_dns_verified; // Bool which is true if all DNS names/txs are verifed, false if not
  std::vector<ddns_object> ddns_list; // Storage of DDNS in blockchain
  
  
};
