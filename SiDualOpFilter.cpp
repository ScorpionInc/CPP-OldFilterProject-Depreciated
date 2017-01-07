#include "SiDualOpFilter.hpp"
using namespace si::io;

//Variables

//Constructors
SiDualOpFilter::SiDualOpFilter(const FilterOption bothOption) : boost::iostreams::dual_use_filter(), inputMode_(bothOption), outputMode_(bothOption) {
}
SiDualOpFilter::SiDualOpFilter(const FilterOption inputOption, const FilterOption outputOption) : boost::iostreams::dual_use_filter(), inputMode_(inputOption), outputMode_(outputOption) {
}
SiDualOpFilter::~SiDualOpFilter(){}

//Functions
template<typename Sink>
bool SiDualOpFilter::put (Sink &dest, int c){
    FilterOutput output;
    char_type t = (char_type)c;
    switch(this->outputMode_){
    case(FilterOptionD):
        output = this->d(t);
        break;
    case(FilterOptionE):
        output = this->e(t);
        break;
    case(FilterOption_):
    default:
        break;
    }
    if(output.hasOutput)boost::iostreams::put(dest, output.output);
    return(true);
}
template<typename Source>
int SiDualOpFilter::get(Source& src){
    FilterOutput output;
    while(true){
        int next = boost::iostreams::get(src);
        char_type t = (char_type)next;
        switch(this->inputMode_){
        case(FilterOptionD):
            output = this->d(t);
            break;
        case(FilterOptionE):
            output = this->e(t);
            break;
        case(FilterOption_):
        default:
            break;
        }
        if(output.hasOutput)break;
    }
    return(output.output);
}
SiDualOpFilter::FilterOutput SiDualOpFilter::d(const char_type byte){/**/FilterOutput o;return(o);}
SiDualOpFilter::FilterOutput SiDualOpFilter::e(const char_type byte){/**/FilterOutput o;return(o);}

//Methods
template<typename Device>
void SiDualOpFilter::close(Device&, std::ios_base::openmode){
    /*Overload*/
}

//Operators
