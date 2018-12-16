#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "dns_util/ddns_util.h" // Header file for ddns_util definitions

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
