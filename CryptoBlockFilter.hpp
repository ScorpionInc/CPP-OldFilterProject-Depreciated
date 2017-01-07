/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Created on: 20161021
 * Last Updated: 20161021
 * Purpose: Adds CBC/CTR Block Encryption Functionality to Boost's iostream's
 *          library via the Crypto++ Library
 * TODO:
 * #1.) Make a TODO List...
//*/

#include <boost/shared_ptr.hpp>
#include <boost/iostreams/filtering_stream.hpp>

#include <cryptopp/modes.h> //! CBC / CTR / Ect.

#ifndef CRYPTOBLOCKFILTER_HPP_
#define CRYPTOBLOCKFILTER_HPP_

namespace si{
namespace crypto{
    template<typename blockModeClass>
    class CryptoBlockFilter : public boost::iostreams::dual_use_filter{
    public:
        typedef char char_type;
        struct category : boost::iostreams::dual_use_filter_tag, boost::iostreams::closable_tag {};
        CryptoBlockFilter(const boost::shared_ptr<CryptoPP::SecByteBlock> key, const boost::shared_ptr<uint8_t*> iv = nullptr, const size_t ivLength = 0u);
        ~CryptoBlockFilter();
        template<typename Sink>
        bool put (Sink &dest, int c);
        template<typename Source>
        int get(Source& src);
        template<typename Device>
        void close(Device&, std::ios_base::openmode);
        void setKey(const boost::shared_ptr<CryptoPP::SecByteBlock> key);
    protected:
        boost::shared_ptr<CryptoPP::SecByteBlock> _key;
        typename blockModeClass::Encryption _encrypt;
        typename blockModeClass::Decryption _decrypt;
        int handle(const int c);
    private:
    };
}
}

#endif // CRYPTOBLOCKFILTER_HPP_
