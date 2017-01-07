#include "SixorFilter2.hpp"
using namespace si::crypto;

//Variables

//Constructors
SixorFilter2::SixorFilter2(const std::string key, const FilterOption inputOption, const FilterOption outputOption) : SiDualOpFilter(inputOption, outputOption), sEncrypt_(), sDecrypt_() {
    this->setKey(key);
}
SixorFilter2::SixorFilter2(const std::vector<uint8_t>& key, const FilterOption inputOption, const FilterOption outputOption) : SiDualOpFilter(inputOption, outputOption), sEncrypt_(), sDecrypt_() {
    this->setKey(key);
}
SixorFilter2::SixorFilter2(const uint8_t* key, const size_t cLength, const FilterOption inputOption, const FilterOption outputOption) : SiDualOpFilter(inputOption, outputOption), sEncrypt_(), sDecrypt_() {
    this->setKey(key, cLength);
}
SixorFilter2::SixorFilter2(const std::string key, const FilterOption bothOption) : SiDualOpFilter(bothOption), sEncrypt_(), sDecrypt_() {
    this->setKey(key);
}
SixorFilter2::SixorFilter2(const std::vector<uint8_t>& key, const FilterOption bothOption) : SiDualOpFilter(bothOption), sEncrypt_(), sDecrypt_() {
    this->setKey(key);
}
SixorFilter2::SixorFilter2(const uint8_t* key, const size_t cLength, const FilterOption bothOption) : SiDualOpFilter(bothOption), sEncrypt_(), sDecrypt_() {
    this->setKey(key, cLength);
}
SixorFilter2::~SixorFilter2(){}

//Functions
bool SixorFilter2::hasKey() const{
    return(this->sEncrypt_.hasKey() || this->sDecrypt_.hasKey());
}
SixorFilter2::FilterOutput SixorFilter2::d(const uint8_t byte){
    FilterOutput rfov;
    rfov.hasOutput = true;
    rfov.output = this->sDecrypt_.handle(byte);
    return(rfov);
}
SixorFilter2::FilterOutput SixorFilter2::e(const uint8_t byte){
    FilterOutput rfov;
    rfov.hasOutput = true;
    rfov.output = this->sDecrypt_.handle(byte);
    return(rfov);
}

//Methods
void SixorFilter2::setKey(const std::string key){
    this->sEncrypt_.setKey(key);
    this->sDecrypt_.setKey(key);
}
void SixorFilter2::setKey(const std::vector<uint8_t>& key){
    this->sEncrypt_.setKey(key);
    this->sDecrypt_.setKey(key);
}
void SixorFilter2::setKey(const uint8_t* key, const size_t cLength){
    this->sEncrypt_.setKey(key, cLength);
    this->sDecrypt_.setKey(key, cLength);
}

//Operators
