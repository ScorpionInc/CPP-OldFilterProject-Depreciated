/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Purpose: Provide an implementation of the SixorBase in Boost's iostreams library.
 *          Can Encrypt and Decrypt with same instance using same key however uses more memory.
 * Created: 20161023
 * Last Updated: 20161023
 * TODO:
 * #1.) Make a TODO List...
//*/
#include <iostream>
#include <vector>
#include <string>

#include "SixorBase.hpp"

#include "SiDualOpFilter.hpp"
using namespace si::io;

#ifndef SIXORFILTER2_HPP_

namespace si{
namespace crypto{
    class SixorFilter2 : public SiDualOpFilter{
    public:
        SixorFilter2(const std::string key = std::string(), const FilterOption inputOption = FilterOptionE, const FilterOption outputOption = FilterOptionD);
        SixorFilter2(const std::vector<uint8_t>& key, const FilterOption inputOption, const FilterOption outputOption);
        SixorFilter2(const uint8_t* key, const size_t cLength, const FilterOption inputOption, const FilterOption outputOption);
        SixorFilter2(const std::string key, const FilterOption bothOption);
        SixorFilter2(const std::vector<uint8_t>& key, const FilterOption bothOption);
        SixorFilter2(const uint8_t* key, const size_t cLength, const FilterOption bothOption);
        ~SixorFilter2();
        bool hasKey() const;
        void setKey(const std::string key);
        void setKey(const std::vector<uint8_t>& key);
        void setKey(const uint8_t* cArray, const size_t cLength);
    protected:
        SixorBase sEncrypt_;
        SixorBase sDecrypt_;
        FilterOutput d(const uint8_t byte);
        FilterOutput e(const uint8_t byte);
    private:
    };
}
}

#endif//SIXORFILTER2_HPP_
