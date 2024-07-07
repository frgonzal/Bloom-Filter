#include "../../headers/db/NoFilterDataBase.hpp"
#include <fstream>
#include <thread>
#include <chrono>



NoFilterDataBase::NoFilterDataBase(const std::string &dbFileName)
    : dbFileName(dbFileName) {};



std::tuple<bool, bool, std::string> NoFilterDataBase::search(const std::string &key) const {
    std::ifstream file(dbFileName);
    if (!file.is_open()) throw std::runtime_error("Could not open file.");

    std::tuple<bool, bool, std::string> result = std::make_tuple(false, true, "not found");

    std::string line;
    while (std::getline(file, line)) {
        if (line == key) {
            result = std::make_tuple(true, true, line);
        }
    }

    file.close();
    return result;
}



std::string NoFilterDataBase::filterName() const {
    return "NoFilter";
}
