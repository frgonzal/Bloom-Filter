#pragma once
#include "Filter.hpp"
#include <string>


/** A class to represent a bloom filter. */
class NullFilter : public Filter{

public:

    NullFilter() = default;

    ~NullFilter() = default;

    /** Insert a key into the bloom filter. */
    void insert(const std::string &key) override;

    /** Check if a key is in the filter. */
    bool contains(const std::string &key) const override;

    std::string toString() const override;
};