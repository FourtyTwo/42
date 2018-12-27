#include <iostream>

#include "ddns_db.h"

// Method for adding DDNS to database file, note that since DDNS isn't fully implemented (theres no message signing process yet)
// all this method will really do is just add whatever DDNS is in the arguments since theres no way to validate it yet
// After basic testing with transactions and the like what we have now for DDNS verfication will be replaced with message signing

bool ddns_db::add_ddns_to_file(ddns_object ddns)
{
    std::ofstream file_input;
    file_input.open("ddns.db", ios::app); // IIRC the file path this will be saved in as of now is the same directory as the 42d executable or whatever, later that will be changed to the correct directory (.42/...)
    /*  TODO - When DDNS verfication is fully implemented add verification here, psuedocode below:
    
        if(ddns.verify_ddns() == true)
        {
            // write to file etc etc
            // file_input.write((char*)&ddns, sizeof(ddns));
            return true;
        }
        if(ddns.verify_ddns() == false)
        {
            std::cout << "Runtime error on file ddns_db.cpp, line 22: DDNS object from argument returned false on method ddns.verify_ddns(), its likely that the inputed DDNS object is not valid" << std::endl; // fuck you ill use easylogger when you get my cold dead corpse and force me to use it
            return false;
        }
    
    */
    file_input.write((char*)&ddns, sizeof(ddns));
    return true;
}



// cant really implement this method yet for the reasons stated before
// bool ddns_db::verify_ddns_db()
// {
//     ...
// }




// This method is for getting DDNS objects from other peers by checking their db and see if there are new additions to it,
// this one isn't implemented yet but for the sake of me remembering what hogwash I was doing this is how grabbing DDNS from peers will work
// Step 1: Ask all peers in peerlist about their DDNS names or if they have any new ones
// Step 2: Once a new DDNS name is found, get it and verify it against YOUR blockchain
// Step 2.5: To verify, scan the blockchain for a transaction hash associated with that DDNS name, if its a match, verify the transaction again, and then the signed message (Note: Since the DDNS names are added via transactions, often times the name will already be in all of the peers DDNS DB, so is likely this method won't be used very often)
// Step 3: If it verifies, add it to the DB and if it doesn't don't add it and notify other peers about the peer with the possibly invalid DB list

/*

bool ddns_object::get_ddns_from_peer();
{
    ...
}

*/

// This method basically searches the DDNS DB for a certain DDNS object with a specific name, then returns it

ddns_object ddns_db::return_ddns_from_name(std::string name)
{
    std::ifstream file_output;
    file_output.open("ddns.db", ios::in); 
    bool found_ddns = false; // check
    ddns_object final; // object to put actual DDNS object in
    ddns_object load_object; // All DDNS info in the ddns.db file will be loaded into this object, then pushed into the vector
    file_output.read((char*)&load_object, sizeof(load_object)); 
    // Then check all the DDNS names
        while (!file_output.eof()) 
        { 
        if (ddns_load.return_ddns_name() == name) 
        { 
            found_ddns = true;
            final.push_ddns_info("3", ddns_load.return_ddns_host(), ddns_load.return_ddns_name()); // 3 is there for testing
        } 
  
        file_output.read((char*)&ddns_load, sizeof(ddns_load)); 
       } 
       // check if it was found
       if(found_ddns == true)
       {
          return final;
       }
       if(found_ddns == false)
       {
          std::cout << "Runtime warning on ddns_db.cpp, line 90: method argument for ddns name was not found" << std::endl;
          return; // nothing since it wasn't found
       }
}

ddns_object ddns_db::return_ddns_from_hash(std::string hash)
{
    std::ifstream file_output;
    file_output.open("ddns.db", ios::in); 
    bool found_ddns = false; // check
    ddns_object final; // object to put actual DDNS object in
    ddns_object load_object; // All DDNS info in the ddns.db file will be loaded into this object, then pushed into the vector
    file_output.read((char*)&load_object, sizeof(load_object)); 
    // Then check all the DDNS names
        while (!file_output.eof()) 
        { 
        if (ddns_load.return_ddns_hash() == hash) 
        { 
            found_ddns = true;
            final.push_ddns_info("3", ddns_load.return_ddns_host(), ddns_load.return_ddns_name()); // 3 is there for testing
        } 
  
        file_output.read((char*)&load_object, sizeof(load_object)); 
       } 
       // check if it was found
       if(found_ddns == true)
       {
          return final;
       }
       if(found_ddns == false)
       {
          std::cout << "Runtime warning on ddns_db.cpp, line 90: method argument for ddns hash was not found" << std::endl;
          return; // nothing since it wasn't found
       }
}

// This method basically just loads all DDNS from db into a vector and then returns it
std::vector<ddns_object> ddns_db::load_and_return_ddns_db()
{
    std::ifstream file_output;
    std::vector<ddns_object> return_vector;
    file_output.open("ddns.db", ios::in); 
    ddns_object load; // object that loads everything into vector
    ddns_object final;
    file_output.read((char*)&load, sizeof(load)); 
    while (!file_output.eof()) 
    { 
         
        if (0 == 0) // because
        { 
            final.push_ddns_info("3", load.return_ddns_host(), load.return_ddns_name()); // 3 is there for testing
            return_vector.push_back(final);
            
        } 
  
        file_output.read((char*)&load, sizeof(load)); 
    } 
    // return vector then bruh
    return return_vector;
}


