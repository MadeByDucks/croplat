#pragma once
#include <string>
#include "logger.h"

#define LOG_MSG(Type, Function, MSG) \
{ \
    std::string message = std::string(Type) + ": () " + MSG; \
    Logger::getInstance()->log(message); \
}

#define LOG_ERROR(Function, MSG) LOG_MSG("Error",   Function, MSG)
#define LOG_WARN (Function, MSG) LOG_MSG("Warnning",Function, MSG)
#define LOG_INFO (Function, MSG) LOG_MSG("Info",    Function, MSG)
#define LOG_DEBUG(Function, MSG) LOG_MSG("Debug",   Function, MSG)
