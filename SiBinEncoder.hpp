/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Purpose: My Fugly Binary Encoder/Decoder
 * Created: 20161029
 * Updated: 20161029
 * TODO:
 * #1.) Create a TODO List...
//*/

#include <vector>

#include "SiEncoder.hpp"

#ifndef SIBINENCODER_HPP_
#define SIBINENCODER_HPP_

namespace si{
namespace io{
    class SiBinEncoder : public SiEncoder{
    public:
        SiBinEncoder(std::vector<uint8_t>* output = nullptr);
        SiBinEncoder(boost::shared_ptr<std::vector<uint8_t> > output);
        ~SiBinEncoder();
        size_t encode(const uint8_t b);
        size_t decode(const uint8_t b);
        size_t flush();
    protected:
        std::vector<uint8_t> decodeBuffer_;
    private:
    };
}
}

#endif // SIBINENCODER_HPP_
