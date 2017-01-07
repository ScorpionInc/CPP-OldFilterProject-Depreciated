#include <iostream>
#include <string>
#include <functional>
#include <vector>

#include <boost/iostreams/filtering_stream.hpp>

#include "SiDualOpFilter.hpp"//!Needed?

#ifndef SIESCAPEFILTER_HPP_
#define SIESCAPEFILTER_HPP_

namespace si{
    namespace io{
        class SiEscapeFilter{
        public:
            struct ESCAPE_ITEM{
                std::string escape;
                size_t paramCount;
                std::function< std::string(...) >* onEscape;
            };
            SiEscapeFilter();
            ~SiEscapeFilter();
            bool addEscape(const std::string escaped, const size_t parameters, std::function< std::string(...) > onEscape);
            bool removeEscape();
            void clearEscapes();
        protected:
            std::vector<char> escapes_;
        private:
        };
    }
}

#endif//SIESCAPEFILTER_HPP_
