#ifndef __ENUMVALUE_H__
#define __ENUMVALUE_H__

#include <Enumeration/details/Enumeration.hpp>

namespace Enumeration{
    class EnumValue{
        private:
            Enumeration& e;
            std::string value;
        public:
            EnumValue(Enumeration& x,std::string v):
                e{x},
                value{v}
                {}

            auto getEnumeration(){
                return e;
            }

            auto getValue(){
                return value;
            }
    };
}


#endif // __ENUMVALUE_H__