#ifndef __ENUM_DETAILS_H__
#define __ENUM_DETAILS_H__

#include <Enumeration/details/Enumeration.hpp>
#include <Enumeration/details/EnumValue.hpp>

namespace Enumeration{
extern Property::Property<Enumeration> takes;

namespace details{
extern Property::Property<std::string> value;
}

class Enum
{
  Property::PropertiesContainer<std::string> properties{ takes, details::value};

  void
  setProperty (Property::details::PropertyContainer<std::string> pc)
  {
    properties (pc);
  }

public:
  template <typename... t> Enum (t... properties)
  {
    (setProperty (properties), ...);
  }


  Enum(const Enum&)=default;
  Enum& operator=(const Enum&)=default;


  auto getValue(){
    return properties[details::value];
  }


  auto getEnumeration(){
    return properties[takes];
  }

  auto getString(){
    return std::string{"{"}+getEnumeration().getString() +","+getValue()+"}";
  }

  Enum& operator=(EnumValue e){
    if(e.getEnumeration() != getEnumeration())
      throw  std::string{"EnumerationError : Enumeration Type ("} + e.getEnumeration().getName() + ") does not match the type (" + e.getEnumeration().getName() + ")";

    setProperty(details::value = e.getValue());
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& o,Enum e){
    o<<e.getString();
    return o;
  }


  bool operator==(Enum e){
    return getString() == e.getString();
  }

  bool operator!=(Enum e){
    return getString() != e.getString();
  }

};
}

#endif // __ENUM_DETAILS_H__