#ifndef LIBPRGE_DIMENSION_ENUMS_HH
#define LIBPRGE_DIMENSION_ENUMS_HH
#include <libprge/base/config.hh>

namespace libprge
{

/**
 * @brief dimension enum structure
 */
struct EDimension
{
    enum ENUM : i32
    {
        DIMENSION_IS_UNDEFINED,
        DIMENSION_IS_2D,
        DIMENSION_IS_3D,
        DIMENSION_IS_MISC, // this should be last option
    };

    struct CODE
    {
        inline static const char *DIMENSION_IS_UNDEFINED = "Undefined Dimension";
        inline static const char *DIMENSION_IS_2D = "Two Dimension";
        inline static const char *DIMENSION_IS_3D = "Three Dimension";
        inline static const char *DIMENSION_IS_MISC = "Misc Dimension";
    };
};

} // namespace libprge

#endif // LIBPRGE_DIMENSION_ENUMS_HH
