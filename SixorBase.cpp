#include "SixorBase.hpp"
using namespace si::crypto;

//Variables

//Constructors
SixorBase::SixorBase(const std::string key, const bool _encrypt) : SixorBase(reinterpret_cast<const uint8_t*>(key.data()), key.length(), _encrypt){
}
SixorBase::SixorBase(const std::vector<uint8_t>& key, const bool _encrypt) : encrypt(_encrypt), _key(key), _step(0u){
}
SixorBase::SixorBase(const uint8_t* cArray, const size_t cLength, const bool _encrypt) : encrypt(_encrypt), _key(), _step(0u){
    for(size_t i = 0u; i < cLength; i++)
        this->_key.push_back(cArray[i]);
}
SixorBase::~SixorBase(){}

//Functions
uint8_t SixorBase::rol(const uint8_t _byte){
    uint8_t rbv = _byte;
    uint8_t high = (rbv & 0x80);
    rbv <<= 1u;
    rbv |= (high>>7u);
    return(rbv);
}
uint8_t SixorBase::rol(const uint8_t _byte, uint8_t _amount){
    uint8_t rbv = _byte;
    while(_amount >= 8u)_amount -= 8u;
    for(size_t i = 0u; i < _amount; i++)
        rbv = SixorBase::rol(rbv);
    return(rbv);
}
uint8_t SixorBase::ror(const uint8_t _byte){
    uint8_t rbv = _byte;
    uint8_t low = (_byte & 1u);
    rbv >>= 1u;
    rbv |= (low<<7u);
    return(rbv);
}
uint8_t SixorBase::ror(const uint8_t _byte, uint8_t _amount){
    uint8_t rbv = _byte;
    while(_amount >= 8u)_amount -= 8u;
    for(size_t i = 0u; i < _amount; i++)
        rbv = SixorBase::ror(rbv);
    return(rbv);
}
uint8_t SixorBase::xorAll(const std::vector<uint8_t>& buffer){
    uint8_t rbv = static_cast<uint8_t>(0u);
    if(buffer.size() <= 0u)return(rbv);
    rbv = buffer[0];
    for(size_t i = 1u; i < buffer.size(); i++)
        rbv = (rbv ^ buffer[i]);
    return(rbv);
}
bool SixorBase::hasKey() const{
    return(this->_key.size() > 0u);
}
uint8_t SixorBase::handle(uint8_t _byte){
    if(!this->hasKey())return(_byte);
    while(this->_step >= this->_key.size())this->_step -= this->_key.size();
    uint8_t raw = _byte;
    uint8_t keyByte = this->_key[this->_step];
    if(!this->encrypt)raw = SixorBase::ror(raw, this->_step);
    uint8_t data = (raw ^ keyByte);
    this->_key[this->_step] = (this->encrypt ? data : raw);
    if(this->encrypt)data = SixorBase::rol(data, this->_step);
    this->_step++;
    return(data);
}
uint8_t SixorBase::xorKey() const{
    return(SixorBase::xorAll(this->_key));
}
std::string SixorBase::handle(const std::string str, const bool littleEndian){
    std::string rsv = str;
    this->handle(reinterpret_cast<uint8_t*>((char*)&rsv[0u]), rsv.length(), littleEndian);
    return(rsv);
}

//Methods
void SixorBase::handle(uint8_t* cArray, const size_t cLength, const bool littleEndian){
    if(cLength <= 0u)return;
    for(size_t i = (littleEndian ? (cLength - 1u) : 0u);
        (littleEndian ? (i >= 0u) : (i < cLength));
        (littleEndian ? (i--) : (i++))){
        cArray[i] = this->handle(cArray[i]);
        if(littleEndian && i == 0u)break;
    }
}
void SixorBase::setKey(const std::string key){
    this->setKey(reinterpret_cast<const uint8_t*>(key.data()), key.length());
}
void SixorBase::setKey(const std::vector<uint8_t>& key){
    this->setKey(&key[0], key.size());
}
void SixorBase::setKey(const uint8_t* cArray, const size_t cLength){
    this->_step = 0u;
    while(this->_key.size() > cLength)this->_key.pop_back();
    while(this->_key.size() < cLength)this->_key.push_back(0x00);
    for(size_t i = 0u; i < cLength; i++)
        this->_key[i] = cArray[i];
}

//Operators
