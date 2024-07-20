#include <iostream>
#include "../headers/db/NoFilterDataBase.hpp"
#include "../headers/db/BloomFilterDataBase.hpp"
#include "vector"
#include "iostream"

static char namesDB[] = "db/names.csv";

/* Size of the filter */
static size_t sizeFilter = 100000;

/* Number of hash functions */
static size_t numHashes = 7;



int main(int argc, char* argv[]){

    /* Data bases */
    NoFilterDataBase nfdb(namesDB);
    BloomFilterDataBase bfdb(namesDB, sizeFilter, numHashes);

    std::cout << "Searching for JOHN" << std::endl;
    std::cout << "\tNoFilterDataBase:    " << std::get<0>(nfdb.search("JOHN")) << std::endl;
    std::cout << "\tBloomFilterDataBase: " << std::get<0>(bfdb.search("JOHN")) << std::endl;
    std::cout << "\n";

    std::cout << "Searching for NAVARRO" << std::endl;
    std::cout << "\tNoFilterDataBase:    " << std::get<0>(nfdb.search("NAVARRO")) << std::endl;
    std::cout << "\tBloomFilterDataBase: " << std::get<0>(bfdb.search("NAVARRO")) << std::endl;
    

    return 0;
}