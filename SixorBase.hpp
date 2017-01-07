/* Notes:
 * Version: 1.0.0.0
 * Author: ScorpionInc
 * Purpose: Simple XOR Stream-Cipher Base WARNING: Non-Authenticated Unsecure OTP
 * Created: 20161023
 * Last Updated: 20161023
 * TODO:
 * #1.) Add A Rotation based on key step/key length... Complete!
//*/

//#include <iostream>//!Debugging
#include <string>
#include <vector>

#ifndef SIXORBASE_HPP_
#define SIXORBASE_HPP_

namespace si{
namespace crypto{
    class SixorBase{
    public:
        bool encrypt;
        SixorBase(const std::string key = std::string(), const bool encrypt = true);
        SixorBase(const std::vector<uint8_t>& key, const bool encrypt = true);
        SixorBase(const uint8_t* cArray, const size_t cLength, const bool encrypt = true);
        ~SixorBase();
        static uint8_t rol(const uint8_t byte);
        static uint8_t rol(const uint8_t byte, uint8_t amount);
        static uint8_t ror(const uint8_t byte);
        static uint8_t ror(const uint8_t byte, uint8_t amount);
        static uint8_t xorAll(const std::vector<uint8_t>& buffer);
        bool hasKey() const;
        uint8_t handle(uint8_t _byte);
        std::string handle(const std::string str, const bool littleEndian = false);
        void handle(uint8_t* cArray, const size_t cLength, const bool littleEndian = false);
        void setKey(const std::string key);
        void setKey(const std::vector<uint8_t>& key);
        void setKey(const uint8_t* cArray, const size_t cLength);
    protected:
        std::vector<uint8_t> _key;
        size_t _step;
        uint8_t xorKey() const;
    private:
    };
}
}

#endif // SIXORBASE_HPP_
