#pragma once
#include <string>
#include <vector>
#include <functional>
#include "Filter.hpp"

/** @class A filter class to represent a bloom filter. */
class BloomFilter : public Filter {

public:

    /** Constructor for the BloomFilter class.
     *  @param size The size of the bloom filter.
     *  @param numHashes The number of hash functions to use.
     */
    BloomFilter(size_t size, size_t numHashes);

    /** Destructor for the BloomFilter class. */
    ~BloomFilter() = default;

    /** Insert a key into the bloom filter.
     *  @param key The key to insert.
     */
    void insert(const std::string &key) override;

    /** Check if a key is in the bloom filter.
     *  One-sided error: if the function returns false, the key is definitely not in the bloom filter.  
     *  @param key The key to check.
     *  @return True if the key is in the bloom filter, false otherwise.
     */
    bool contains(const std::string &key) const override;

    std::string toString() const override;

private:

    /* The size of the bloom filter. */
    size_t size;

    /* The number of hash functions to use. */
    size_t numHashes;

    /* The bit array of the bloom filter. */
    std::vector<bool> bitArray;

    /* The hash functions to use. */
    std::vector<std::function< size_t (std::string) >> hash;
};