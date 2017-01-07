/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Created on: 20161106
 * Last Updated: 20161106
 * Purpose: A Superclass of Boost's iostream's Dual_Use_Filters with dual methods of handling data
 * TODO:
 * #1.) Add Wide-Character Support...
 * #1.) Make a TODO List...
//*/

#include <boost/iostreams/filtering_stream.hpp>

#ifndef SIDUALOPFILTER_HPP_
#define SIDUALOPFILTER_HPP_

namespace si{
namespace io{
    class SiDualOpFilter : public boost::iostreams::dual_use_filter{
    public:
        typedef char char_type;
        struct category : boost::iostreams::dual_use_filter_tag, boost::iostreams::closable_tag {};
        enum FilterOption{
            FilterOption_,//!Do Nothing(Pass)
            FilterOptionD,//!Apply FunctionD
            FilterOptionE,//!Apply FunctionE
            FilterOptionB //!Apply Both FunctionD & E
        };
        struct FilterOutput{
            bool hasOutput = false;
            char_type output = static_cast<char_type>(0u);
        };
        FilterOption inputMode_;
        FilterOption outputMode_;
        SiDualOpFilter(const FilterOption bothOption = FilterOption_);
        SiDualOpFilter(const FilterOption inputOption, const FilterOption outputOption);
        ~SiDualOpFilter();
        template<typename Sink>
        bool put (Sink &dest, int c);
        template<typename Source>
        int get(Source& src);
        template<typename Device>
        void close(Device&, std::ios_base::openmode);
        virtual FilterOutput d(const char_type byte);
        virtual FilterOutput e(const char_type byte);
    protected:
    private:
    };
}
}

#endif//SIDUALOPFILTER_HPP_
