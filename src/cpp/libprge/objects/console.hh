#ifndef LIBPRGE_CONSOLE_HH
#define LIBPRGE_CONSOLE_HH
#include <libprge/base/config.hh>
#include <libprge/functions/date_and_times_funcs.hh>

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/os.hpp>

namespace libprge
{

/**
 * @brief console object class
 * 
 * @note mostly use for console loging
 */
class console : public Object
{
    GDCLASS(console, Object);
private:
    /* data */

protected:
    static void _bind_methods();

public:
    console(/* args */);
    ~console();

    /**
     * @brief show args to console as log
     * 
     * @tparam Args 
     * @param args 
     */
    template <typename... Args>
    static void log(const Args &...args)
    {
        int timezone = dateAndTimeFunctions::localTimeZone();
        std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

        UtilityFunctions::print("[", currentTime.c_str(), "]", " LOG: ", args...);
    }
    // binding log
    static void blog(const Array args)
    {
        std::vector<Variant> variants;
        for (int i = 0; i < args.size(); ++i)
        {
            variants.push_back(args[i]);
        }

        if (variants.size() > 0)
        {
            String message = String(variants[0]);
            for (size_t i = 1; i < variants.size(); ++i)
            {
                message += " " + String(variants[i]);
            }
            log(message);
        }
    }

    //////////////////////////////////////////////////////

    /**
     * @brief show args to console as log in debug
     * 
     * @tparam Args 
     * @param args 
     */
    template <typename... Args>
    static void log_debug(const Args &...args)
    {
        if (OS::get_singleton()->is_debug_build())
        {
            int timezone = dateAndTimeFunctions::localTimeZone();
            std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

            UtilityFunctions::print("[", currentTime.c_str(), "]", " DEBUG: ", args...);
        }
    }
    // binding log_debug
    static void blog_debug(const Array args)
    {
        if (OS::get_singleton()->is_debug_build())
        {
            std::vector<Variant> variants;
            for (int i = 0; i < args.size(); ++i)
            {
                variants.push_back(args[i]);
            }

            if (variants.size() > 0)
            {
                String message = String(variants[0]);
                for (size_t i = 1; i < variants.size(); ++i)
                {
                    message += " " + String(variants[i]);
                }
                log(message);
            }
        }
    }
    
    //////////////////////////////////////////////////////

    /**
     * @brief show args to console as warning
     * 
     * @tparam Args 
     * @param args 
     */
    template <typename... Args>
    static void warning(const Args &...args)
    {
        int timezone = dateAndTimeFunctions::localTimeZone();
        std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

        UtilityFunctions::push_warning("[", currentTime.c_str(), "]", " WARNING: ", args...);
    }
    // binding warning
    static void bwarning(const Array args)
    {
        std::vector<Variant> variants;
        for (int i = 0; i < args.size(); ++i)
        {
            variants.push_back(args[i]);
        }

        if (variants.size() > 0)
        {
            String message = String(variants[0]);
            for (size_t i = 1; i < variants.size(); ++i)
            {
                message += " " + String(variants[i]);
            }
            warning(message);
        }
    }

    //////////////////////////////////////////////////////

    /**
     * @brief show args to console as log in debug
     * 
     * @tparam Args 
     * @param args 
     */
    template <typename... Args>
    static void warning_debug(const Args &...args)
    {
        if (OS::get_singleton()->is_debug_build())
        {
            int timezone = dateAndTimeFunctions::localTimeZone();
            std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

            UtilityFunctions::push_warning("[", currentTime.c_str(), "]", " WARNING DEBUG: ", args...);
        }
    }
    // binding warning_debug
    static void bwarning_debug(const Array args)
    {
        if (OS::get_singleton()->is_debug_build())
        {
            std::vector<Variant> variants;
            for (int i = 0; i < args.size(); ++i)
            {
                variants.push_back(args[i]);
            }

            if (variants.size() > 0)
            {
                String message = String(variants[0]);
                for (size_t i = 1; i < variants.size(); ++i)
                {
                    message += " " + String(variants[i]);
                }
                log(message);
            }
        }
    }

    //////////////////////////////////////////////////////

    /**
     * @brief show args to console as error
     * 
     * @tparam Args 
     * @param args 
     */
    template <typename... Args>
    static void error(const Args &...args)
    {
        int timezone = dateAndTimeFunctions::localTimeZone();
        std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

        UtilityFunctions::push_error("[", currentTime.c_str(), "]", " ERROR: ", args...);
    }
    // binding error
    static void berror(const Array args)
    {
        std::vector<Variant> variants;
        for (int i = 0; i < args.size(); ++i)
        {
            variants.push_back(args[i]);
        }

        if (variants.size() > 0)
        {
            String message = String(variants[0]);
            for (size_t i = 1; i < variants.size(); ++i)
            {
                message += " " + String(variants[i]);
            }
            error(message);
        }
    }

    //////////////////////////////////////////////////////

    /**
     * @brief show args to console as error in debug
     * 
     * @tparam Args 
     * @param args 
     */
    template <typename... Args>
    static void error_debug(const Args &...args)
    {
        if (OS::get_singleton()->is_debug_build())
        {
            int timezone = dateAndTimeFunctions::localTimeZone();
            std::string currentTime = dateAndTimeFunctions::UTC::timeZone::toStringOffset(timezone);

            UtilityFunctions::push_error("[", currentTime.c_str(), "]", " ERROR DEBUG: ", args...);
        }
    }
    // binding error_debug
    static void berror_debug(const Array args)
    {
        if (OS::get_singleton()->is_debug_build())
        {
            std::vector<Variant> variants;
            for (int i = 0; i < args.size(); ++i)
            {
                variants.push_back(args[i]);
            }

            if (variants.size() > 0)
            {
                String message = String(variants[0]);
                for (size_t i = 1; i < variants.size(); ++i)
                {
                    message += " " + String(variants[i]);
                }
                error_debug(message);
            }
        }
    }
};

// default class name for console
inline static cchar *console_CLASS = "console";

// global console pointer
static console *pConsole;

} // namespace libprge

#endif // LIBPRGE_CONSOLE_HH
