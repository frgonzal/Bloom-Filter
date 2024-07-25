#include "../../headers/db/DataBase.hpp"
#include "../../headers/filter/Filter.hpp"
#include "../../headers/filter/NullFilter.hpp"
#include "../../headers/filter/BloomFilter.hpp"
#include <fstream>
#include <optional>
#include <unistd.h>
#include <thread>
#include <iostream>





DataBase::DataBase(const std::string &dbFileName, size_t size, size_t numHashes) 
    : dbFileName(dbFileName), filter(new BloomFilter(size, numHashes)) {

    std::ifstream file(dbFileName);
    if(!file.is_open()){
        throw std::runtime_error("Could not open file.");
    }

    std::string line;
    while(std::getline(file, line)){
        filter->insert(line);
    }

    file.close();
}


DataBase::DataBase(const std::string &dbFileName) 
    : dbFileName(dbFileName), filter(new NullFilter()) {}


DataBase::~DataBase() {
    delete filter;
}


std::tuple<bool, bool, std::string> DataBase::search(const std::string &key) const {

    if (!filter->contains(key)) {
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



std::string DataBase::filterName() const {
    return filter->toString();
}