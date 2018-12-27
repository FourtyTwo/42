#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "dns_util/ddns_util.h" // Header file for ddns_util definitions


bool ddns_util::load_dns_from_db(ddns_db db_object)
{
    std::vector<ddns_object> thingy = db_object.load_and_return_ddns_db();
    ddns_list = thingy;
    return true;
}

int ddns_util::return_dns_count()
{
    int size = ddns_list.size(); // Returns the size of the ddns vector
    return size;  
}

std::vector<ddns_object> ddns_util::return_all_known_dns()
{
   std::vector<ddns_object> current_objects = ddns_list;
   return current_objects; // change this later
}

ddns_object ddns_util::return_dns_info_by_hash(std::string hash)
{
    // find the hash in the list of all DNS names
    for(int i = 0; i < ddns_list.size(); i++)
    {
        std::string prehash = ddns_list.at(i).owner_hash;
        if(prehash == hash) // check if it matches
        {
            return ddns_list.at(i);   
        }
    }
}

ddns_object ddns_util::return_dns_info_by_name(std::string ddns_name)
{
    // find the name in the list of dns stuff
    for(int i = 0; i < ddns_list.size(); i++)
    {
        std::string prename = ddns_list.at(i).ddns_name;
        if(prename == ddns_name)
        {
            return ddns_list.at(i);
        }
    }
}
        
std::string ddns_util::return_dns_ip_by_name(std::string ddns_name)
{
    // find ip by name in dns vector
    for(int i = 0; i < ddns_list.size(); i++)
    {
        std::string prename = ddns_list.at(i).ddns_name;
        if(prename == name)
        {
            return ddns_list.at(i).ddns_host;
        }
    }
}

std::string ddns_util::return_dns_ip_by_hash(std::string hash)
{
    // you sheep really think we landed on the moon? you believe in the moon? sheep the lot of you!
    for(int i = 0; i < ddns_list.size(); i++)
    {
        std::string prehash = ddns_list.at(i).owner_hash;
        if(owner_hash == hash)
        {
           return ddns_list.at(i).ddns_host;    
        }
    }
}
