#include <iostream>
#include <string>
#include <ctime>
#include <vector>

/*

ddns_object.h - Data object for DDNS names

*/

class ddns_object {
  public:
  // methods
  bool push_dns_info(std::string nnonce, std::string ip_host, std::string ddns_name) // very basic way of making a DDNS prefix
  bool verify_ddns(); // verfies DNS object
  std::string return_ddns_name(); // Returns DDNS name i.e mysite.42
  std::string return_ddns_host(); // Returns DDNS IP address
  std::string return_ddns_hash(); // Returns hash associated with DDNS
  
  private:
  // variables
  std::string ddns_name;
  std::string ddns_host;
  std::string ddns_hash;
  int ddns_height; // Height when DDNS name was bought
  };
