#ifndef __ENUMERATION_C__
#define __ENUMERATION_C__


#include <Enumeration/Enumeration.hpp>
#include <Property/Property.hpp>
#include <Enumeration/details/EnumValue.hpp>

namespace Enumeration{
    const Version::Version ProjectVersion = std::string{"1.0.0"};
    Property::Property<std::string> name{"name",""};
    Property::Property<std::vector<std::string>> values{"values",{""}};
    Property::Property<Enumeration> takes{"takes",{name = "Default",values = {""}}};

    namespace details{
        Property::Property<std::string> value{"value",""};
    }

    
    EnumValue Enumeration::operator[](std::string s){
        for(auto v:properties[values])
            if(v == s)
                return {*this,s};
        throw std::string{"Enumeration Value : "}+ s+ "Not Present";
    }

}

#endif // __ENUMERATION_C__