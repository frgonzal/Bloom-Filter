#include "DataBase.hpp"



/** @class DB
 *  A class to represent a database.
 */
class NoFilterDataBase : public DataBase {

public:
    /**  Constructor for the DB class.
     *   @param dbFileName The name of the file to read the database from.
     */
    NoFilterDataBase(const std::string &dbFileName);

    /** Destructor for the DB class */
    ~NoFilterDataBase() = default;

    /** Search for a key in the database. */
    std::tuple<bool, bool, std::string> search(const std::string &key) const override;

    /* Get the filter name. */
    std::string filterName() const override;

private:
    /** The name of the file to read the database from. */
    std::string dbFileName;

};