#ifndef LIBPRGE_STRING_CONST_HH
#define LIBPRGE_STRING_CONST_HH
#include <string>

namespace libprge
{

/**
 * @brief string internal object access collection
 */
struct STRINGS_INTERNAL
{
    inline static const std::string numeric = "0123456789";
    inline static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    inline static const std::string alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    inline static const std::string special_character = "~!@#$%^&*()_+{}|:\"<>?`-=[]';,./\\";
    inline static const std::string alphanumeric_with_special_character = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~!@#$%^&*-_=+";

    inline static const std::string BASE36_DIGITS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    inline static const char HEX_DIGITS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
};

/**
 * @brief string scenes object access collection
 * 
 */
struct STRINGS_SCENES
{
    inline static const char *SCENE_IS_ERROR = "SCENE_IS_ERROR";
    inline static const char *SCENE_IS_UNDEFINED = "SCENE_IS_UNDEFINED";
};

struct STRINGS_OS_GODOT
{
    inline static const char *LINUX = "Linux";
    inline static const char *WINDOWS = "Windows";
    inline static const char *MACOS = "macOS";
};

} // namespace libprge

#endif // LIBPRGE_STRING_CONST_HH
