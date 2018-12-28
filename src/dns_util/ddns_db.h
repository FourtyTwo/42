#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "ddns_object.h"

/*

    ddns_db.h - Database object for handling DDNS and DB

*/

class ddns_db {
  public:
  // methods
  bool add_ddns_to_file(ddns_object ddns); // adds a DNS object to the ddns db if possible
  bool verify_ddns_db(); // verifies all known domain names - stuff can't really be verifed yet
  bool get_ddns_from_peer(); // todo
  ddns_object return_ddns_from_name(std::string name); // returns DDNS object from DB based upon inputed DNS name i.e (coin42.42, frty.cnpools.42 etc etc)
  ddns_object return_ddns_from_hash(std::string hash); // you know I remember the days when you wore an onion on your belt since it was the style back in the day and it only cost 25 cents to go on the fairy, and back then they called nickels bees, "5 bees for the fairy!" they would say, and back then I was trying to go on the fairy to shelbyville to get new soles for my shoes when I saw FDR and superman having a race, and FDR won! But the history books won't tell you that...
  std::vector<ddns_object> load_and_return_ddns_db(); // loads DDNS into ddns_db_list and returns vector
  private:
  // variables
  std::vector<ddns_object> ddns_db_list; // Store all the dns in this then write it to a file
  
};

/*

Just to note my current thought process with how DNS names are going to be verifed in two ways
Check 1: First, the daemon confirms that the transaction associated with the DNS name is correct and valid, basically just 
checks it
Check 2: Then, it checks the signed message (which will replace the owner_hash since using just hashes is far less secure) and if 
the signed message is valid then it adds it to the DB. I think that's pretty fullproof but that needs to still be checked once its
implemented fully

*/
