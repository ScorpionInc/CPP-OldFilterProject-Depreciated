#include "CryptoHashFilter.cpp"
using namespace si::crypto;

#ifdef CRYPTOHASHFILTER_CPP_
#ifndef ALLCRYPTOHASHFILTERS_CPP_
#define ALLCRYPTOHASHFILTERS_CPP_

//#ifdef CRYPTOPP_VERSION
//#if CRYPTOPP_VERSION >= 565

#include <cryptopp/blake2.h>

template class CryptoHashFilter<CryptoPP::BLAKE2b>;
template class CryptoHashFilter<CryptoPP::BLAKE2s>;

//#endif//CRYPTOPP_VERSION >= 565
//#endif // CRYPTOPP_VERSION

#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>

template class CryptoHashFilter<CryptoPP::SHA1>;
template class CryptoHashFilter<CryptoPP::SHA224>;
template class CryptoHashFilter<CryptoPP::SHA256>;
template class CryptoHashFilter<CryptoPP::SHA384>;
template class CryptoHashFilter<CryptoPP::SHA512>;

template class CryptoHashFilter<CryptoPP::SHA3_224>;
template class CryptoHashFilter<CryptoPP::SHA3_256>;
template class CryptoHashFilter<CryptoPP::SHA3_384>;
template class CryptoHashFilter<CryptoPP::SHA3_512>;

#include <cryptopp/tiger.h>

template class CryptoHashFilter<CryptoPP::Tiger>;

#include <cryptopp/whrlpool.h>

template class CryptoHashFilter<CryptoPP::Whirlpool>;

#include <cryptopp/ripemd.h>

template class CryptoHashFilter<CryptoPP::RIPEMD128>;
template class CryptoHashFilter<CryptoPP::RIPEMD160>;
template class CryptoHashFilter<CryptoPP::RIPEMD256>;
template class CryptoHashFilter<CryptoPP::RIPEMD320>;

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <cryptopp/md5.h>

template class CryptoHashFilter<CryptoPP::Weak1::MD2>;
template class CryptoHashFilter<CryptoPP::Weak1::MD4>;
template class CryptoHashFilter<CryptoPP::Weak1::MD5>;

#include <cryptopp/panama.h>

template class CryptoHashFilter<CryptoPP::Weak::PanamaHash<CryptoPP::BigEndian> >;
template class CryptoHashFilter<CryptoPP::Weak::PanamaHash<CryptoPP::LittleEndian> >;

#undef CRYPTOPP_ENABLE_NAMESPACE_WEAK

#endif//ALLCRYPTOHASHFILTERS_CPP_
#endif//CRYPTOHASHFILTER_CPP_
