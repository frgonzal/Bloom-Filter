#include "../../headers/filter/NullFilter.hpp"
#include <string>



/** Insert a key into the bloom filter. */
void NullFilter::insert(const std::string &key) {
    return;
}

/** Check if a key is in the filter. 
 *  @return Always true.
*/
bool NullFilter::contains(const std::string &key) const {
    return true;
}

std::string NullFilter::toString() const {
    return "NoFilter";
}