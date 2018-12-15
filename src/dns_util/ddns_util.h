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
  int return_ddns_count(); // Returns the current count of all DNS names in the blockchain 
  std::vector<dns_object> return_all_known_dns(); // Returns all known DDNS names in the blockchain into a vector
  ddns_object return_dns_info_by_hash(std::string hash); // Returns DDNS object by DDNS hash
  ddns_object return_dns_info_by_name(std::string ddns_name); // Returns DDNS object by DDNS name
  std::string return_dns_ip_by_name(std::string ddns_name); // Return DDNS IP by name
  std::string return_dns_ip_by_hash(std::string hash); // Returns DDNS IP by hash
  bool verify_ddns_list(); // Verifys current DDNS list to make sure there isn't any invalid DDNS
  bool verify_ddns_transaction(ddns_transaction ddns_tx); // Verifies a certain DDNS transaction
  
  
  private:
  // variables
  int current_ddns_count; // Int of all current dns names in blockchain
  bool all_dns_verified; // Bool which is true if all DNS names/txs are verifed, false if not
  
  
};
