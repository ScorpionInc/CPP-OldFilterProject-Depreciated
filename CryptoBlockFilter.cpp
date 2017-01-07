#include "CryptoBlockFilter.hpp"
using namespace si::crypto;

#ifndef CRYPTOBLOCKFILTER_CPP_
#define CRYPTOBLOCKFILTER_CPP_

//Variables

//Constructors
template<typename blockModeClass>
CryptoBlockFilter<blockModeClass>::CryptoBlockFilter(const boost::shared_ptr<CryptoPP::SecByteBlock> key, const boost::shared_ptr<uint8_t*> iv, const size_t ivLength) : boost::iostreams::dual_use_filter(), _key(key) {
}
template<typename blockModeClass>
CryptoBlockFilter<blockModeClass>::~CryptoBlockFilter(){}

//Functions
template<typename blockModeClass>
template<typename Sink>
bool CryptoBlockFilter<blockModeClass>::put (Sink &dest, int c){
    //!TODO
    return(true);
}
template<typename blockModeClass>
template<typename Source>
int CryptoBlockFilter<blockModeClass>::get(Source& src){
    //!TODO
    return(0u);
}
template<typename blockModeClass>
int CryptoBlockFilter<blockModeClass>::handle(const int c){
    //!TODO
    return(c);
}

//Methods
template<typename blockModeClass>
template<typename Device>
void CryptoBlockFilter<blockModeClass>::close(Device&, std::ios_base::openmode){
    //!TODO
}

//Operators

#endif//CRYPTOBLOCKFILTER_CPP_
