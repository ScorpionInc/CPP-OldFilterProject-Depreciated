/* Notes:
//*/

#include <iostream>//!Debugging
#include <vector>

#include "SiEncoder.hpp"

#ifndef SIHEXENCODER_HPP_
#define SIHEXENCODER_HPP_

namespace si{
namespace io{
    class SiHexEncoder : public SiEncoder{
    public:
        bool lowercase;
        SiHexEncoder(std::vector<uint8_t>* output = nullptr);
        SiHexEncoder(const boost::shared_ptr<std::vector<uint8_t> > output);
        ~SiHexEncoder();
        size_t encode(const uint8_t b);
        size_t decode(const uint8_t b);
        size_t flush();
    protected:
        std::vector<uint8_t> decodeBuffer_;
    private:
    };
}
}

#endif//SIHEXENCODER_HPP_
