/* Notes:
 * Version: 1.0.0.0
 * Author: Scorpion Inc
 * Purpose: Boost IOStreams implentation of their dual-use-filters for my statistical based dictionary compression
 * Created: 20161028
 * Updated: 20161028
 * TODO:
 * #1.) Make a TODO list...
//*/

#include <iostream>
#include <vector>
#include <math.h>

#include <boost/iostreams/filtering_stream.hpp>

#ifndef SICFILTER_HPP_
#define SICFILTER_HPP_

namespace si{
namespace io{
    class SicFilter: public boost::iostreams::dual_use_filter{
    public:
        typedef char char_type;
        struct category : boost::iostreams::dual_use_filter_tag {};
        struct SicItem{
            std::vector<uint8_t> value;
            size_t id;
            size_t idcat(){
                return((size_t)floor(((double)(this->id % sizeof(size_t)))));
            };
        };
        SicFilter();
        ~SicFilter();
        template<typename Sink>
        bool put (Sink &dest, int c);
        template<typename Source>
        int get(Source& src);
    protected:
        std::vector<uint8_t> escape_;
        std::vector<SicItem> items_;
    private:
    };
}
}

#endif // SICFILTER_HPP_
