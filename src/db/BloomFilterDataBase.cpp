#include "../../headers/db/BloomFilterDataBase.hpp"
#include <fstream>
#include <optional>
#include <unistd.h>
#include <thread>
#include <iostream>



BloomFilterDataBase::BloomFilterDataBase(const std::string &dbFileName, size_t size, size_t numHashes)
    : dbFileName(dbFileName), bf(size, numHashes) {
    
    std::ifstream file(dbFileName);
    if(!file.is_open()){
        throw std::runtime_error("Could not open file.");
    }

    std::string line;
    while(std::getline(file, line)){
        bf.insert(line);
    }

    file.close();
}



std::tuple<bool, bool, std::string> BloomFilterDataBase::search(const std::string &key) const {

    if(!bf.contains(key)){
        return std::make_tuple(false, false, "not found");
    }

    std::ifstream file(dbFileName);
    if (!file.is_open()) throw std::runtime_error("Could not open file.");

    std::tuple<bool,bool,std::string> result = std::make_tuple(false, true, "not found");

    std::string line;
    while(std::getline(file, line)) {
        if(line == key) {
            result = std::make_tuple(true, true, line);
        }
    }

    file.close();
    return result;
}



std::string BloomFilterDataBase::filterName() const {
    return "BloomFilter";
}
