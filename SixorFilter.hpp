/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Purpose: Provide an implementation of the SixorBase in Boost's iostreams library.
 * Created: 20161023
 * Last Updated: 20161023
 * TODO:
 * #1.) Make a TODO List...
//*/

#include <boost/iostreams/filtering_stream.hpp>

#include "SixorBase.hpp"

#ifndef SIXORFILTER_HPP_
#define SIXORFILTER_HPP_

namespace si{
namespace crypto{
    class SixorFilter : public SixorBase, public boost::iostreams::dual_use_filter{
    public:
        typedef char char_type;
        struct category : boost::iostreams::dual_use_filter_tag {};
        SixorFilter(const std::string key = std::string(), const bool encrypt = true);
        SixorFilter(const std::vector<uint8_t>& key, const bool encrypt = true);
        SixorFilter(const uint8_t* cArray, const size_t cLength, const bool encrypt = true);
        ~SixorFilter();
        template<typename Sink>
        bool put(Sink& dest, int c);
        template<typename Source>
        int get(Source& src);
    protected:
    private:
    };
}
}

#endif // SIXORFILTER_HPP_
