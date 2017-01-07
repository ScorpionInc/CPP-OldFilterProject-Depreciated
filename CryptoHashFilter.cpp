#include "CryptoHashFilter.hpp"
using namespace si::crypto;

#ifndef CRYPTOHASHFILTER_CPP_
#define CRYPTOHASHFILTER_CPP_

//Variables

//Constructors
template<typename hashClass>
CryptoHashFilter<hashClass>::CryptoHashFilter(boost::shared_ptr<boost::array<uint8_t, DIGESTSIZE> > digest) : boost::iostreams::dual_use_filter(), _hash(), _digest(digest){
}
template<typename hashClass>
CryptoHashFilter<hashClass>::CryptoHashFilter(boost::array<uint8_t, DIGESTSIZE>* ptr) : CryptoHashFilter<hashClass>(boost::shared_ptr<boost::array<uint8_t, DIGESTSIZE> >(ptr) ){
}
/*
template<typename hashClass>
CryptoHashFilter<hashClass>::CryptoHashFilter(const CryptoHashFilter& chf) : boost::iostreams::dual_use_filter(), _hash(), _digest(nullptr){
    //!Needed?
    //this->_digest = boost::shared_ptr<boost::array<uint8_t, DIGESTSIZE> >(chf._digest.get(), boost::null_deleter());
    std::cout << "This New Obj. Old Digest Address: " << &(*this->_digest.get()) << "\n";
    this->_hash = chf._hash;
    this->_digest = chf._digest;
    std::cout << "" << chf._digest << "\n";
    std::cout << "Copy Con. Source Digest Address: " << &(*chf._digest.get()) << "\n";
}
//*/
template<typename hashClass>
CryptoHashFilter<hashClass>::~CryptoHashFilter(){
    if(this->_digest != nullptr)
        delete this->_digest.get();//!Needed?
}

//Functions
template<typename hashClass>
unsigned int CryptoHashFilter<hashClass>::digest(uint8_t* target) const {
    //!Assumes target c_array is DIGESTSIZE in size
    if(target == nullptr || this->_digest == nullptr)return(0u);
    std::copy(this->_digest.get()->begin(), this->_digest.get()->end(), target);
    return(CryptoHashFilter<hashClass>::DIGESTSIZE);
}
template<typename hashClass>
unsigned int CryptoHashFilter<hashClass>::final(uint8_t* target){
    if(target == nullptr)return(0u);
    this->_hash.Final(target);
    return(CryptoHashFilter<hashClass>::DIGESTSIZE);
}
template<typename hashClass>
template<typename Sink>
bool CryptoHashFilter<hashClass>::put(Sink &dest, int c){
    this->update(c);//!Update Hash
    boost::iostreams::put(dest, c);//!Pass Along Data
    return(true);//!Consumes Value
}
template<typename hashClass>
template<typename Source>
int CryptoHashFilter<hashClass>::get(Source& src){
    int c = boost::iostreams::get(src);
    this->update(c);//!Update Hash
    return(c);//!Pass Along Data
}

//Methods
template<typename hashClass>
template<typename Device>
void CryptoHashFilter<hashClass>::close(Device&, std::ios_base::openmode){
    this->final();
}
template<typename hashClass>
void CryptoHashFilter<hashClass>::digest(std::ostream& os_) const {
    if(os_.bad() || this->_digest == nullptr)return;
    os_.write((char*)(this->_digest.get()->data()), this->_digest.get()->size());
}
template<typename hashClass>
void CryptoHashFilter<hashClass>::final(){
    if(this->_digest == nullptr)return;
    this->_hash.Final(this->_digest.get()->data());
}
template<typename hashClass>
void CryptoHashFilter<hashClass>::update(int c){
    //!Int type allows for wide-character types. Convert to byte array(?)
    //uint8_t buff[sizeof(c)];
    //this->_hash.Update(buff, sizeof(c));
    uint8_t b = (uint8_t)c;
    this->_hash.Update((uint8_t*)&b, 1u);
}

//Operators

#endif//CRYPTOHASHFILTER_CPP_
