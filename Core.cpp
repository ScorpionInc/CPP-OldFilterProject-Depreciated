#include <iostream>
#include <string>

#include "SicFilter.hpp"

const std::string TEST_DATA = "MV ENTY0 ~ 0 ~\nATK ENTY0 1 ~ ~\nDIE ENTY1\nMV ENTY0 ~ ~ -1\nMSG ENTY0 You Suck n00b!\nMSG Fuck You ****!\nRESPAWN ENTY1 0 0 0\nMV ENTY0 ~ ~ ~\n";
const size_t TEST_DATA_SIZE = TEST_DATA.length();

int main(int argc, char* argv[]){
    std::cout << "[INFO]: Application has started." << std::endl;
    boost::iostreams::filtering_ostream fos;
    fos.set_auto_close(true);
    fos.push(std::cout);
    fos << "[INFO]: Test\n";
    fos.pop();
    std::cout << "[INFO]: Application has stopped." << std::endl;
    return(0);
}
