#include "SiHexEncoder.hpp"
using namespace si::io;

//Variables

//Constructors
SiHexEncoder::SiHexEncoder(std::vector<uint8_t>* output) : SiHexEncoder(boost::shared_ptr<std::vector<uint8_t> >(output)){
}
SiHexEncoder::SiHexEncoder(const boost::shared_ptr<std::vector<uint8_t> > output) : SiEncoder(output), lowercase(false), decodeBuffer_() {
}
SiHexEncoder::~SiHexEncoder(){}

//Functions
size_t SiHexEncoder::encode(const uint8_t b){
    //!0->48u;9->57u;a->97u;f->102u;A->65u;F->70u;
    if(this->output_ == nullptr)return(0u);
    size_t rsv = 2u;
    uint8_t big, little;
    big = (b & 0xF0) >> 4u; little = (b & 0x0F);//!0->15 16 total
    if(big >= 0u && big <= 9u)
        //Numeric Output
        this->output_.get()->push_back((uint8_t)(big + 48u));
    else
        //Character Output
        this->output_.get()->push_back((uint8_t)((big - 10u) + ((this->lowercase) ? 97u : 65u)));
    if(little >= 0u && little <= 9u)
        //Numeric Output
        this->output_.get()->push_back((uint8_t)(little + 48u));
    else
        //Character Output
        this->output_.get()->push_back((uint8_t)((little - 10u) + ((this->lowercase) ? 97u : 65u)));
    return(rsv);
}
size_t SiHexEncoder::decode(const uint8_t b){
    if((b < 48u || b > 57u) && (b < 65u || b > 70u) && (b < 97u || b > 102u))return(0u);//!Invalid
    if(this->decodeBuffer_.size() == 0u){
        this->decodeBuffer_.push_back(b);
        return(0u);
    }
    if(this->output_ == nullptr){
        if(this->decodeBuffer_.size() != 0u)
            this->decodeBuffer_[0u] = b;
        return(0u);
    }
    uint8_t big = (this->decodeBuffer_[0u] - 48u), little = (b - 48u);
    this->decodeBuffer_.pop_back();
    //!0->48u;9->57u;a->97u;f->102u;A->65u;F->70u;
    if(big > 9u){
        //Character Value
        big -= 7u;
        if(big > 15u)
            big -= 32u;
    }
    if(little > 9u){
        //Character Value
        little -= 7u;
        if(little > 15u)
            little -= 32u;
    }
    this->output_.get()->push_back((uint8_t)((big << 4u) | little));
    return(1u);
}
size_t SiHexEncoder::flush(){
    if(this->decodeBuffer_.size() == 0u)return(0u);
    return(this->decode(static_cast<uint8_t>(48u)));
}

//Methods

//Operators
