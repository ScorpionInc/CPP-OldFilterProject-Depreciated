#include "SiEncoder.hpp"
using namespace si::io;

//Variables

//Constructors
SiEncoder::SiEncoder(std::vector<uint8_t>* output) : SiEncoder(boost::shared_ptr<std::vector<uint8_t> >(output)){
}
SiEncoder::SiEncoder(const boost::shared_ptr<std::vector<uint8_t> > output) : output_(output){
}
SiEncoder::~SiEncoder(){}

//Functions
size_t SiEncoder::encode(const uint8_t c){/**/return(0u);}
size_t SiEncoder::encode(const uint8_t* cArray, const size_t cLength){
    if(cArray == nullptr)return(0u);
    size_t rsv = 0u;
    for(size_t i = 0u; i < cLength; i++)rsv += this->encode(cArray[i]);
    return(rsv);
}
size_t SiEncoder::encode(const std::vector<uint8_t>& v){
    return(this->encode(v.data(), v.size()));
}
size_t SiEncoder::decode(const uint8_t c){/**/return(0u);}
size_t SiEncoder::decode(const uint8_t* cArray, const size_t cLength){
    if(cArray == nullptr)return(0u);
    size_t rsv = 0u;
    for(size_t i = 0u; i < cLength; i++)rsv += this->decode(cArray[i]);
    return(rsv);
}
size_t SiEncoder::decode(const std::vector<uint8_t>& v){
    return(this->decode(v.data(), v.size()));
}
size_t SiEncoder::flush(){/**/return(0u);}

//Methods
#include <iostream>
void SiEncoder::setOutput(std::vector<uint8_t>* output){
    this->setOutput(boost::shared_ptr<std::vector<uint8_t> >(output));
}
void SiEncoder::setOutput(const boost::shared_ptr<std::vector<uint8_t> > output){
    this->output_ = output;
    //!std::cout << "Penis\n";//!Debugging?
}

//Operators
