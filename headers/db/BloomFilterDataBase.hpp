#include "DataBase.hpp"
#include "../filter/BloomFilter.hpp"



class BloomFilterDataBase : public DataBase {

public:
    
    /** Constructor for the BloomFilterDataBase class.
    *  @param dbFileName The name of the file to read the database from.
    *  @param size The size of the bloom filter.
    *  @param numHashes The number of hash functions to use.
    */
    BloomFilterDataBase(const std::string &dbFileName, size_t size, size_t numHashes);

    /** Destructor for the BloomFilterDataBase class */
    ~BloomFilterDataBase() = default;

    /** Search for a key in the database. */
    std::tuple<bool, bool, std::string> search(const std::string &key) const override;

    /* Get the class name. */
    std::string className() const override;

    /* Get the filter name. */
    std::string filterName() const override;

private:

    /** The name of the file to read the database from. */
    std::string dbFileName;

    /** The bloom filter used to search for keys. */
    BloomFilter bf;

};