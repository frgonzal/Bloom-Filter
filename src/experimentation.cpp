#include "../headers/db/DataBase.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <chrono>
#include <stdio.h>


/* Data base Files */
char namesDB[] = "db/names.csv";
char otherNamesDB[] = "db/otherNames.csv";

/* If true, save the results of the experimentation */
bool save = false;

/* Size of the data bases */
const size_t otherNamesSize = 71727;
const size_t namesSize = 93889;

/* Size of the filter */
size_t sizeFilter = 1000000;

/* Number of hash functions */
size_t numHashes = 7;


/** 
 *  @brief Get the search keys for the experimentation.
 * 
 *  @param queries The number of queries to perform.
 *  @param inDBPercentage The percentage of keys that are in the data base.
 *  @param seed The seed for the random number generator.
 *  @return A vector with the search keys.
 */
std::vector<std::string> getSearchKeys(size_t queries, double inDBPercentage, size_t seed = 8376){
    srand(seed);

    if(queries*inDBPercentage > namesSize || queries*(1-inDBPercentage) > otherNamesSize){
        throw std::runtime_error("Not enough keys in the data bases.");
    }

    std::vector<std::string> searchKeys;
    std::vector<std::string> inDB;
    std::vector<std::string> notInDB;
    std::string line;

    std::ifstream DBFile(namesDB);
    if(!DBFile.is_open()) throw std::runtime_error("Could not open file.");
    inDB.reserve(namesSize);
    while(std::getline(DBFile, line)){
        inDB.push_back(line);
    }
    DBFile.close();

    std::shuffle(inDB.begin(), inDB.end(), std::mt19937(rand()));
    for(size_t i=0; i<(size_t)queries*inDBPercentage; i++){
        searchKeys.push_back(inDB[i]);
    }

    std::ifstream notInDBFile(otherNamesDB);
    if(!notInDBFile.is_open()) throw std::runtime_error("Could not open file.");

    notInDB.reserve(otherNamesSize);
    while(std::getline(notInDBFile, line)){
        notInDB.push_back(line);
    }
    notInDBFile.close();

    std::shuffle(notInDB.begin(), notInDB.end(), std::mt19937(rand()));
    for(size_t i = (size_t)queries*inDBPercentage; i < queries; i++){
        searchKeys.push_back(notInDB[i]);
    }

    std::shuffle(searchKeys.begin(), searchKeys.end(), std::mt19937(std::random_device()()));
    return searchKeys;
}


/** 
 *  @brief Save the result of the experimentation.
 * 
 *  @param time The elapsed time.
 *  @param N The number of queries.
 *  @param p The percentage of keys that are in the data base.
 *  @param DB The data base used.
 *  @param found Number of keys found.
 *  @param foundInFilter Number of keys found in the filter.
 */
void save_result(double time, size_t N, double p, std::string DB, size_t found, size_t foundInFilter){
    std::ofstream file("results/results.csv", std::ios_base::app);
    if(!file.is_open()) throw std::runtime_error("Could not open file.");
    file << time << "," << N << "," << p << "," << sizeFilter << "," << numHashes << "," << DB << "," << found << "," << foundInFilter << "\n";
    file.close();
}


/** Perform a search in the given data base.
 * 
 *  @tparam DB The type of the data base.
 *  @param db The data base to search in.
 *  @param keys The keys to search.
 */
std::tuple<double, size_t, size_t> search(const DataBase &db, const std::vector<std::string> &keys){
    std::cout << "Searching in " << db.filterName() << " Data Base\n";

    size_t totalFound = 0;
    size_t totalFoundInFilter = 0;
  
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto &key : keys) {
        auto [found, foundInFilter, res] = db.search(key);
        totalFound += found ? 1 : 0;
        totalFoundInFilter += foundInFilter ? 1 : 0;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "\tElapsed time: " << elapsed.count() << "s\n\n";

    return {elapsed.count(), totalFound, totalFoundInFilter};
}


/* Main function for the experimentation. */
int main(int argc, char* argv[]){
    if(argc > 1 && std::string(argv[1]) == "--save") 
        save = true;
    if(argc > 3){
        sizeFilter = std::atoll(argv[2]);
        numHashes = std::atoll(argv[3]);
    }
    

    /* Propotion of keys that are in the data base */
    std::vector<double> P = {0.0, 1.0/4, 1.0/2, 3.0/4, 1.0};

    /* Data bases */
    DataBase nfdb(namesDB);
    DataBase bfdb(namesDB, sizeFilter, numHashes);

    /* for N in {2^10, 2^12, 2^14, 2^16} */
    for(size_t i = 10; i <= 16; i += 2){
        size_t N = 1 << i;
        /* for p in {0, 1/4, 1/2, 3/4, 1} */
        for (double p : P){
            printf("\nExperimentation with 2^%lu queries, %.2f in DB, %lu size filter and %lu hash functions\n\n", i, p, sizeFilter, numHashes);
            std::vector<std::string> keys = getSearchKeys(N, p);
            auto [timeNF, totalFoundNF, totalFoundInFilterNF] = search(nfdb, keys);
            auto [timeBF, totalFoundBF, totalFoundInFilterBF] = search(bfdb, keys);

            if(save){
                save_result(timeNF, N, p, nfdb.filterName(), totalFoundNF, totalFoundInFilterNF);
                save_result(timeBF, N, p, bfdb.filterName(), totalFoundBF, totalFoundInFilterBF);
            }
        }
    }

    return 0;
}