#include<Logger/Logger.hpp>

using namespace Logger;
using namespace Logger::LoggerProperty;
int main(){
    [[maybe_unused]]Logger::Logger l{enable = false,level = 3};
    return 0;
}