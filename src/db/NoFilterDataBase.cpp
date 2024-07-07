#include "../../headers/db/NoFilterDataBase.hpp"
#include <fstream>
#include <thread>
#include <chrono>



NoFilterDataBase::NoFilterDataBase(const std::string &dbFileName)
    : dbFileName(dbFileName) {};



std::tuple<bool, bool, std::string> NoFilterDataBase::search(const std::string &key) const {

    std::ifstream file(dbFileName);
    if(!file.is_open()){
        throw std::runtime_error("Could not open file.");
    }

    std::string line;
    while(std::getline(file, line)){
        if(line == key){
            file.close();
            return std::make_tuple(true, false, line);
        }
    }

    file.close();
    return std::make_tuple(false, false, "not found");
}

std::string NoFilterDataBase::className() const {
    return "No Filter Data Base";
}


std::string NoFilterDataBase::filterName() const {
    return "NoFilter";
}
