#include "hachage.hpp"

size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash {0};

    for (std::string::const_iterator it = s.begin(); it < s.end(); it++) hash+=*it;
    
    return hash % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {0};

    for (size_t i = 0; i < s.size(); i++) hash+=s[i]*i;
    
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash {0};
    size_t power {1};

    for (std::string::const_iterator it = s.begin(); it < s.end(); it++) {
        power*=p;
        hash+=*it*power%m;
    }
    
    return hash;
}