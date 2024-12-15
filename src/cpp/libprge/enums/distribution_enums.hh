#ifndef LIBPRGE_DISTRIBUTION_ENUMS_HH
#define LIBPRGE_DISTRIBUTION_ENUMS_HH
#include <libprge/base/config.hh>

#include <cstdint>

#if LIBPRGE_BUILD_COMPILER_ID == 1
// RESERVED
#elif LIBPRGE_BUILD_COMPILER_ID == 2
#pragma warning (push)
#pragma warning (disable : 4505)
#elif LIBPRGE_BUILD_COMPILER_ID == 3
// RESERVED
#endif

namespace libprge
{

/**
 * @brief distribution OS enum structure
 */
struct EDistributionOS
{
    enum ENUM : int32_t
    {
        DISTRIBUTION_OS_UNDEFINED,
        DISTRIBUTION_OS_LINUX,
        DISTRIBUTION_OS_WINDOWS,
        DISTRIBUTION_OS_MACOS,
    };

    struct CODE
    {
        inline static const char *DISTRIBUTION_OS_UNDEFINED = "Undefined";
        inline static const char *DISTRIBUTION_OS_LINUX = "Linux";
        inline static const char *DISTRIBUTION_OS_WINDOWS = "Windows";
        inline static const char *DISTRIBUTION_OS_MACOS = "MacOs";
    };

    struct fromEnum
    {
        static const char *toString(const ENUM distributionOSEnum)
        {
            const char *result = CODE::DISTRIBUTION_OS_UNDEFINED;

            switch (distributionOSEnum)
            {
                case ENUM::DISTRIBUTION_OS_LINUX: { result = CODE::DISTRIBUTION_OS_LINUX; } break;
                case ENUM::DISTRIBUTION_OS_WINDOWS: { result = CODE::DISTRIBUTION_OS_WINDOWS; } break;
                case ENUM::DISTRIBUTION_OS_MACOS: { result = CODE::DISTRIBUTION_OS_MACOS; } break;
                default: { result = CODE::DISTRIBUTION_OS_UNDEFINED; } break;
            }

            return result;
        }
    };

    // RESERVED: fromString
};

/**
 * @brief distribution store enum structure
 */
struct EDistributionStore
{
    enum ENUM : int32_t
    {
        DISTRIBUTION_STORE_UNDEFINED,
        DISTRIBUTION_STORE_PROTHEGEE,
        DISTRIBUTION_STORE_STEAM,
        DISTRIBUTION_STORE_GOG,
        DISTRIBUTION_STORE_ITCHIO,
    };

    struct CODE
    {
        inline static const char *DISTRIBUTION_STORE_UNDEFINED = "Undefined";
        inline static const char *DISTRIBUTION_STORE_PROTHEGEE = "ProthegeeGame";
        inline static const char *DISTRIBUTION_STORE_STEAM = "Steam";
        inline static const char *DISTRIBUTION_STORE_GOG = "GoG";
        inline static const char *DISTRIBUTION_STORE_ITCHIO = "ItchIo";
    };

    struct fromEnum
    {
        static const char *toString(const ENUM &distributionStoreEnum)
        {
            const char *result = CODE::DISTRIBUTION_STORE_UNDEFINED;

            switch (distributionStoreEnum)
            {
                case ENUM::DISTRIBUTION_STORE_PROTHEGEE: { result = CODE::DISTRIBUTION_STORE_PROTHEGEE; } break;
                case ENUM::DISTRIBUTION_STORE_STEAM: { result = CODE::DISTRIBUTION_STORE_STEAM; } break;
                case ENUM::DISTRIBUTION_STORE_GOG: { result = CODE::DISTRIBUTION_STORE_GOG; } break;
                case ENUM::DISTRIBUTION_STORE_ITCHIO: { result = CODE::DISTRIBUTION_STORE_ITCHIO; } break;
                default: { result = CODE::DISTRIBUTION_STORE_UNDEFINED; } break;
            }

            return result;
        }
    };

    // RESERVED: fromString
};

} // namespace libprge

#if LIBPRGE_BUILD_COMPILER_ID == 1
// RESERVED
#elif LIBPRGE_BUILD_COMPILER_ID == 2
#pragma warning (pop)
#elif LIBPRGE_BUILD_COMPILER_ID == 3
// RESERVED
#endif

#endif // LIBPRGE_DISTRIBUTION_ENUMS_HH
