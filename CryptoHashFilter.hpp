/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Created on: 20161021
 * Last Updated: 20161021
 * Purpose: Adds Hashing Functionality to Boost's iostream's
 *          library via the Crypto++ Library
 * TODO:
 * #1.) Make a TODO List...
//*/

#include <iostream>

#include <boost/core/null_deleter.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <boost/iostreams/filtering_stream.hpp>

#include <cryptopp/cryptlib.h> //!HashTransformation

#ifndef CRYPTOHASHFILTER_HPP_
#define CRYPTOHASHFILTER_HPP_

namespace si{
namespace crypto{
    template<typename hashClass>//!CryptoPP::HashTransformation
    class CryptoHashFilter : public boost::iostreams::dual_use_filter{
    public:
        typedef char char_type;
        const static unsigned int DIGESTSIZE = hashClass::DIGESTSIZE;
        struct category : boost::iostreams::dual_use_filter_tag, boost::iostreams::closable_tag {};
        CryptoHashFilter(boost::shared_ptr<boost::array<uint8_t, DIGESTSIZE> > digest = nullptr);
        CryptoHashFilter(boost::array<uint8_t, DIGESTSIZE>* ptr = nullptr);
        //!CryptoHashFilter(const CryptoHashFilter&) = delete;//!Copy Constructor
        //!CryptoHashFilter(const CryptoHashFilter& chf);//!Copy Constructor
        CryptoHashFilter &operator=(const CryptoHashFilter &) = delete;
        ~CryptoHashFilter();
        unsigned int digest(uint8_t* target) const;//!Assumes sizeof DIGESTSIZE
        unsigned int final(uint8_t* target);//!Assumes sizeof DIGESTSIZE Finalizes Hash
        template<typename Sink>
        bool put (Sink &dest, int c);
        template<typename Source>
        int get(Source& src);
        template<typename Device>
        void close(Device&, std::ios_base::openmode);
        void final();//!Finalizes Hash to Shared Pointer of Array Target
        void digest(std::ostream& os_) const;//!Write digest to Stream
        friend std::ostream& operator<<(std::ostream& out, const CryptoHashFilter<hashClass>& filter){
            filter.digest(out);
            return(out);
        }
    protected:
        hashClass _hash;
        //!Have to use external variable as instance is deleted after closed
        boost::shared_ptr<boost::array<uint8_t, DIGESTSIZE> > _digest;
        void update(int c);
    private:
    };
}
}

#endif // CRYPTOHASHFILTER_HPP_
