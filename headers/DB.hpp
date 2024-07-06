#pragma once
#include <string>

/** @struct DB
 *  @brief A class to represent a database.
 *  @details This class is used to represent a database.
 */
class DB {

public:
    DB(std::string dbFileName);
    ~DB() = default;

    /* Insert a key into the database. */
    void insert(int key);

    /* Remove a key from the database. */
    void remove(int key);

    /* Search for a key in the database. */
    bool search(int key) const;

    /* Print the database. */
    void print();

private:

};