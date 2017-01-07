/* Notes:
 * Version: 1.0.0.0
 * Author: Scorpion Inc
 * Purpose: Provide the encoding functionality of the Crypto++ Library to the Boost IOStreams Library via Filter
 * Created: 20161029
 * Updated: 20161106
//*/

#include <boost/iostreams/filtering_stream.hpp>

#ifndef CRYPTOENCODINGFILTER_HPP_
#define CRYPTOENCODINGFILTER_HPP_

namespace si{
namespace crypto{
    template<typename encodingClass>
    class CryptoEncodingFilter : public boost::iostreams::dual_use_filter{
    public:
        CryptoEncodingFilter();
        ~CryptoEncodingFilter();
    protected:
    private:
    };
}
}

#endif//CRYPTOENCODINGFILTER_HPP_
