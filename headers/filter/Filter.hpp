#pragma once
#include <string>
#include <vector>
#include <functional>


/** A class to represent a bloom filter. */
class Filter {

public:

    Filter() = default;

    virtual ~Filter() = default;

    /** Insert a key into the bloom filter. */
    virtual void insert(const std::string &key) = 0;

    /** Check if a key is in the filter. */
    virtual bool contains(const std::string &key) const = 0;

    virtual std::string toString() const = 0;
};