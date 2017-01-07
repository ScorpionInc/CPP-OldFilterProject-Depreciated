#include "SiBinEncoder.hpp"
using namespace si::io;

//Variables

//Constructors
SiBinEncoder::SiBinEncoder(std::vector<uint8_t>* output) : SiBinEncoder(boost::shared_ptr<std::vector<uint8_t> >(output)){
}
SiBinEncoder::SiBinEncoder(boost::shared_ptr<std::vector<uint8_t> > output) : SiEncoder(output), decodeBuffer_(){
}
SiBinEncoder::~SiBinEncoder(){}

//Functions
size_t SiBinEncoder::encode(const uint8_t b){
    //!0->48u;1->49u;
    if(this->output_ == nullptr)return(0u);
    size_t rsv = 8u;
    for(size_t i = 0u; i < 8u; i++)
        this->output_.get()->push_back((uint8_t)(48u + ((b >> (7u - i)) & 0x01)));
    return(rsv);
}
size_t SiBinEncoder::decode(const uint8_t b){
    //!0->48u;1->49u;
    if(b < 48u || b > 49u)return(0u);//!Ignore
    if(this->decodeBuffer_.size() < 8u){
        this->decodeBuffer_.push_back(b - 48u);
        return(0u);
    }
    if(this->output_ == nullptr){
        //!TODO Add rolling decode buffer(?)
        return(0u);
    }
    uint8_t rbv = static_cast<uint8_t>(0u);
    for(size_t i = 0u; i < 8u; i++)
        rbv |= (this->decodeBuffer_[i] << (7u - i));
    this->output_.get()->push_back(rbv);
    return(1u);
}
size_t SiBinEncoder::flush(){
    if(this->decodeBuffer_.size() == 0u)return(0u);
    for(size_t i = this->decodeBuffer_.size(); i <= 8u; i++)
        this->decode(static_cast<uint8_t>(48u));
    this->decodeBuffer_.empty();
    return(1u);
}

//Methods

//Operators
