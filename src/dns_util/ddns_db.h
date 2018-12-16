#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "ddns_object.h"

class ddns_db {
  public:
  // methods
  bool add_ddns_to_file(ddns_object ddns); // adds a DNS object to the ddns db if possible
  bool verify_ddns_db(); // verifies all known domain names
  bool get_ddns_from_peer(); // todo
  private:
  // variables
  
}
