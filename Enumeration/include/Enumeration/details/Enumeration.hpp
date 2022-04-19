#ifndef __ENUMERATION_DETAILS_H__
#define __ENUMERATION_DETAILS_H__

#include <Enumeration/types.hpp>

namespace Enumeration
{
    extern Property::Property<std::string> name;
    extern Property::Property<std::vector<std::string>> values;
    class EnumValue;

    class Enumeration
    {
      Property::PropertiesContainer<std::string> properties{ name, values };

      void
      setProperty (Property::details::PropertyContainer<std::string> pc)
      {
        properties (pc);
      }

    public:
      template <typename... t> Enumeration (t... properties) requires(sizeof...(t)==2)
      {
        (setProperty (properties), ...);
      }

      Enumeration(const Enumeration&) = default;
      
      Enumeration& operator=(const Enumeration&) =default;

      auto getName(){
        return properties[name];
      }

      auto getValues(){
        return properties[values];
      }

      std::string getString(){
        return std::string{"{"}+getName()+","+std::to_string(getValues())+"}";
      }

      static Enumeration get(std::string s){
        s= s.substr(1,s.length()-2);
        auto f = s.find(",");
        std::string n = s.substr(0,f);
        std::vector<std::string> v;
        s = s.substr(f+1,s.length()-f-1);
        s = s.substr(1,s.length()-2);
        using namespace std;
        auto split =
            [] (string s, string delimiter) ->vector<string> {
              size_t pos_start = 0, pos_end, delim_len = delimiter.length ();
              string token;
              vector<string> res;

              while ((pos_end = s.find (delimiter, pos_start)) != string::npos)
                {
                  token = s.substr (pos_start, pos_end - pos_start);
                  pos_start = pos_end + delim_len;
                  res.push_back (token);
                }

              res.push_back (s.substr (pos_start));
              return res;
            };

            for(auto sf :split(s,","))
              v.push_back(sf);

        return Enumeration{ name = n, values = v };
      }

      EnumValue operator[](std::string s);


      friend std::ostream& operator<<(std::ostream& o,Enumeration& e){
        o<<e.getString();
        return o;
      }

      bool operator==(Enumeration e){
        return getString() == e.getString();
      }
      
      bool operator!=(Enumeration e){
        return getString () != e.getString ();
      }

    };
}

#endif // __ENUMERATION_DETAILS_H__