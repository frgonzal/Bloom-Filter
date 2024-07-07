#pragma once
#include <string>
#include <tuple>



/** @struct DataBase
 *  A class to represent a database.
 */
class DataBase {

public:

    /** Search for a key in the database.
     * 
     * The function searches for a key in the database and returns a tuple with three values:
     * - The first value is a boolean that indicates if the key was found in the database.
     * - The second value is a boolean that indicates if the key was found in the filter.
     * - The third value is a string that contains the value associated with the key if it was found in the database.
     * 
     * When the db searches for a key, it does a grep type search in the database file.
     * It reads the whole file line by line and compares each line with the key and returns the last line that matches the key.
     *   
     * @param key The key to search for.
     * @return A tuple with three values.
     */
    virtual std::tuple<bool, bool, std::string> search(const std::string &key) const = 0;

    /* Get the filter name. */
    virtual std::string filterName() const = 0;
};