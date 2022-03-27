#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <Logger/LoggerProperties.hpp>

namespace Logger
{
class Logger
{
  Property::PropertiesContainer<std::string> properties{
    LoggerProperty::enable, LoggerProperty::level
  };

  void
  setProperty (Property::details::PropertyContainer<std::string> pc)
  {
    properties (pc);
  }

public:
  template <typename... t> Logger (t... properties)
  {
    (setProperty (properties), ...);
  }


};
}

#endif // __LOGGER_H__