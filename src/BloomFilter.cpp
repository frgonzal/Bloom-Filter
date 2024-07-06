#include "../headers/BloomFilter.hpp"


size_t primes[] = {
    997151, 997153, 997163, 997201, 997207, 997219, 997247, 997259, 997267, 997273, 997279, 997307, 997309, 997319,
    997327, 997333, 997343, 997357, 997369, 997379, 997391, 997427, 997433, 997439, 997453, 997463, 997511, 997541,
    997547, 997553, 997573, 997583, 997589, 997597, 997609, 997627, 997637, 997649, 997651, 997663, 997681, 997693,
    997699, 997727, 997739, 997741,
};

std::function<size_t (std::string)> hashConstructor(size_t size, size_t seed){
    size_t prime = primes[seed % (sizeof(primes)/sizeof(primes[0])) ];

    return [prime, size](std::string key){
        return (std::hash<std::string>{}(key) % prime) % size;
    };
}


BloomFilter::BloomFilter(size_t size, size_t numHashes) 
    : size(size), numHashes(numHashes), bitArray(size, false) {
        
    hash.reserve(numHashes);
    for(size_t i = 0; i < numHashes; i++){
        hash[i] = hashConstructor(size, i);
    }
}

void BloomFilter::insert(std::string key) {
    for(size_t i=0; i<numHashes; i++){
        bitArray[hash[i](key)] = true;
    }
}


bool BloomFilter::contains(std::string key) {
    for(size_t i=0; i<numHashes; i++){
        if(!bitArray[hash[i](key)]){
            return false;
        }
    }

    return true;
}



