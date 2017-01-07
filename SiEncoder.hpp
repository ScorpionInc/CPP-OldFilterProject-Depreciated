/* Notes:
 * Version: 1.0.0.0
 * Purpose: Abstract Superclass for my implementation of an encoder
 * Created: 20161029
 * Updated: 20161029
 * TODO:
 * #1.) Create a TODO List...
//*/
#include <vector>

#include <boost/shared_ptr.hpp>

#ifndef SIENCODER_HPP_
#define SIENCODER_HPP_

namespace si{
namespace io{
    class SiEncoder{
    public:
        virtual ~SiEncoder() = 0;
        virtual size_t encode(const uint8_t b);
        size_t encode(const uint8_t* cArray, const size_t cLength);
        size_t encode(const std::vector<uint8_t>& v);
        virtual size_t decode(const uint8_t b);
        size_t decode(const uint8_t* cArray, const size_t cLength);
        size_t decode(const std::vector<uint8_t>& v);
        virtual size_t flush();
        void setOutput(std::vector<uint8_t>* output);
        void setOutput(const boost::shared_ptr<std::vector<uint8_t> > output);
    protected:
        boost::shared_ptr<std::vector<uint8_t> > output_;
        SiEncoder(std::vector<uint8_t>* output = nullptr);
        SiEncoder(const boost::shared_ptr<std::vector<uint8_t> > output);
    private:
    };
}
}

#endif // SIENCODER_HPP_
