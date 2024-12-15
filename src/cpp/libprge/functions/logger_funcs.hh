#ifndef LIBPRGE_LOGGER_FUNCS_HH
#define LIBPRGE_LOGGER_FUNCS_HH
#include <libprge/base/config.hh>
#include <libprge/functions/date_and_time_funcs.hh>

#include <godot_cpp/variant/utility_functions.hpp>

namespace libprge
{

using namespace godot;

namespace logger
{
namespace log
{

/**
 * @brief show args as log message
 * 
 * @param args 
 * @tparam Args
 */
template <typename... Args>
void message(const Args &...args)
{
    int timezone = dateAndTimeFunctions::localTimeZone();
    std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

    UtilityFunctions::print("[", currentTime.c_str(), "]: ", args...);
}

/**
 * @brief show args as log message when build is debug
 * 
 * @param args 
 * @tparam Args
 */
template <typename... Args>
void debug(const Args &...args)
{
    #if LIBPRGE_IS_DEBUG
    int timezone = dateAndTimeFunctions::localTimeZone();
    std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

    UtilityFunctions::print("[", currentTime.c_str(), "] DEBUG: ", args...);
    #endif 
}

/**
 * @brief show args as warning message when build is debug
 * 
 * @param args 
 * @tparam Args
 */
template <typename... Args>
void warningDebug(const Args &...args)
{
    #if LIBPRGE_IS_DEBUG
    int timezone = dateAndTimeFunctions::localTimeZone();
    std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

    UtilityFunctions::push_warning("[", currentTime.c_str(), "] DEBUG WARN: ", args...);
    #endif 
}

/**
 * @brief show args as warning message
 * 
 * @param args 
 * @tparam Args
 */
template <typename... Args>
void warningAlways(const Args &...args)
{
    int timezone = dateAndTimeFunctions::localTimeZone();
    std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

    UtilityFunctions::push_warning("[", currentTime.c_str(), "] WARNING: ", args...);
}

/**
 * @brief show args as error message when build is debug
 * 
 * @param args 
 * @tparam Args
 */
template <typename... Args>
void errorDebug(const Args &...args)
{
    #if LIBPRGE_IS_DEBUG
    int timezone = dateAndTimeFunctions::localTimeZone();
    std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

    UtilityFunctions::push_error("[", currentTime.c_str(), "] DEBUG ERR: ", args...);
    #endif 
}

/**
 * @brief show args as error message
 * 
 * @param args 
 * @tparam Args
 */
template <typename... Args>
void errorAlways(const Args &...args)
{
    int timezone = dateAndTimeFunctions::localTimeZone();
    std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

    UtilityFunctions::push_error("[", currentTime.c_str(), "] ERROR: ", args...);
}

} // namespace log
} // namespace logger

} // namespace libprge

#endif // LIBPRGE_LOGGER_FUNCS_HH
