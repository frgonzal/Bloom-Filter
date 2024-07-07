#include "../../headers/filter/BloomFilter.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
#include <stdlib.h>



/** Returns the first M prime numbers.
 * 
 *  The function reads the first M prime numbers from a file and returns them as a vector.
 * 
 *  The file "primes-to-1000k.txt" contains primes from 900k to 1000k.
 * 
 *  @param M The number of prime numbers to return.
 *  @return A vector containing the first M prime numbers.
 */
std::vector<uint64_t> getNPrimes(size_t numHashes, size_t seed = 1234){
    srand(seed);
    std::vector<uint64_t> primes;
    std::vector<uint64_t> allPrimes;
    allPrimes.reserve(7223);
    primes.reserve(numHashes);

    std::ifstream file("db/primes.csv");
    if(!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }

    std::string line;
    while(std::getline(file, line)){
        allPrimes.push_back(std::stoul(line));
    }

    file.close();

    std::shuffle(allPrimes.begin(), allPrimes.end(), std::mt19937(rand()));
    for(size_t i = 0; i < numHashes; i++){
        primes.push_back(allPrimes[i]);
    }

    return primes;
}


/** Returns a lambda function that hashes a string to a number between 0 and size-1.
 * 
 *  The hash function use the hasa function from the standard library, and then takes the modulo of the prime number
 *  so that it returns different values for each hash function.
 * 
 *  @param size The size of the hash.
 *  @param prime The prime number to use for the hash.
 *  @return A lambda function that hashes a string to a number between 0 and size-1.
 */
std::function<size_t (std::string)> hashConstructor(size_t size, uint64_t prime){
    return [prime, size](std::string key){
        return (std::hash<std::string>{}(key) % prime) % size;
    };
}


BloomFilter::BloomFilter(size_t size, size_t numHashes) 
    : size(size), numHashes(numHashes), bitArray(size, false) {
        
    std::vector<uint64_t> primes = getNPrimes(numHashes);
    if(numHashes != primes.size()) {
        throw std::runtime_error("Not enough prime numbers.");
    }

    hash.reserve(numHashes);
    for(size_t i = 0; i < numHashes; i++){
        hash.push_back(hashConstructor(size, primes[i]));
    }
}

void BloomFilter::insert(const std::string &key) {
    for(size_t i=0; i<numHashes; i++){
        bitArray[hash[i](key)] = true;
    }
}


bool BloomFilter::contains(const std::string &key) const {
    for(size_t i=0; i<numHashes; i++){
        if(!bitArray[hash[i](key)]){
            return false;
        }
    }

    return true;
}



