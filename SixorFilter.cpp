#include "SixorFilter.hpp"
using namespace si::crypto;

//Variables

//Constructors
SixorFilter::SixorFilter(const std::string key, const bool encrypt) : SixorBase(key, encrypt), boost::iostreams::dual_use_filter() {
}
SixorFilter::SixorFilter(const std::vector<uint8_t>& key, const bool encrypt) : SixorBase(key, encrypt), boost::iostreams::dual_use_filter() {
}
SixorFilter::SixorFilter(const uint8_t* cArray, const size_t cLength, const bool encrypt) : SixorBase(cArray, cLength, encrypt), boost::iostreams::dual_use_filter() {
}
SixorFilter::~SixorFilter(){}

//Functions
//*
template<typename Sink>
bool SixorFilter::put(Sink& dest, int i){
    char c = static_cast<char>(i);
    c = reinterpret_cast<char>(this->handle(reinterpret_cast<uint8_t>(c)));
    boost::iostreams::put(dest, static_cast<int>(c));//!Pass Along Data
    return(true);
}
template<typename Source>
int SixorFilter::get(Source& src){
    int i = boost::iostreams::get(src);
    char c = static_cast<char>(i);
    c = reinterpret_cast<char>(this->handle(reinterpret_cast<uint8_t>(c)));
    return(static_cast<int>(c));//!Pass Along Data
}
//*/

//Methods

//Operators
