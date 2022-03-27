#ifndef __LOGGERPROPERTIES_H__
#define __LOGGERPROPERTIES_H__

#include <Logger/types.hpp>

namespace Logger {
namespace LoggerProperty {
static Property::Property<bool> enable{ "enable", true };
static Property::Property<int> level{ "level", 0 };
}
}

#endif // __LOGGERPROPERTIES_H__