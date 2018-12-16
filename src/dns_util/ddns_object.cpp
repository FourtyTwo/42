#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "ddns_object.cpp"
#include "sha256.h" // will switch to sha256 function already in the codebase later

// Basically how this works is the function takes the ip_host (IP address of the site), the DNS
// name, and a sha256 nnonce for any hash. Right now rather than having your addres or something
// sign the prefix like a tx hash is built, for testing purposes the nnonce is essentially the 
// "secret key" or password to access to the DNS name. This is rudimentary at best and has a lot
// of flaws and will soon be changed to a much more secure system

// Remember all of these functions are being coded in a way that they would work in a testnet with one user
// Later once I have the core created I will implement signing rather than this hash system, then
// make it usable with a network of multiple people. Baby steps!

bool ddns_object::push_dns_info(std::string nnonce, std::string pre_ip_host, std::string pre_ddns_name)
{
    // for now the prefix will be 3 objects, the ip_host, the ddns_name and the sha256 hash associated with it
    // and in the prefix itself they will all be seperated by five 0's for testing purposes, will change that later
    
    std::string signing_hash = sha256(nnonce); // get the hash to put in the prefix
    // create the prefix
    std::string dns_prefix_pre = ddns_name + "00000" + ip_host + "00000" + signing_hash;
    std::string prefix_hash = sha256(dns_prefix_pre);
    ddns_prefix = dns_prefix_pre;
    ddns_name = pre_ddns_name
    ddns_host = pre_ip_host
    ddns_prefix_hash = prefix_hash;
    owner_hash = signing_hash;
    return true; // later this function will check the signed message to prove that your submitting a DNS name you own
    
    // The actual DNS name isn't confirmed here though, this just confirms the DNS information. Since the DNS name will
    // be bundled with a transaction, the DNS will be confirmed and pushed to the blockchain when the transaction is
    // confirmed by other nodes.
    
}


/*

bool ddns_object::verify_dns()
{
...
}

TODO: Since the DNS object has nothing to verify since signing the DNS object isn't implemented yet

*/

// The rest of these are just helper functions

std::string ddns_object::return_ddns_name()
{
    return ddns_name;
}

std::string ddns_object::return_ddns_host()
{
    return ddns_host;
}

std::string ddns_object::return_ddns_prefix()
{
    return ddns_prefix;
}

std::string ddns_object::return_ddns_prefix_hash()
{
    return ddns_prefix_hash;
}

std::string ddns_object::return_ddns_owner_hash()
{
    return owner_hash;
}
