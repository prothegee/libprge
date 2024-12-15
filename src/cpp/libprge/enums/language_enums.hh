#ifndef LIBPRGE_LANGUAGE_ENUMS_HH
#define LIBPRGE_LANGUAGE_ENUMS_HH
#include <cstdint>

namespace libprge
{

/**
 * @brief language enum structure
 * 
 */
struct ELanguage
{
    enum ENUM : int32_t
    {
        LANGUAGE_UNDEFINED,
        LANGUAGE_ENGLISH,
        LANGUAGE_BAHASA,
    };

    struct CODE
    {
        inline static const char *LANGUAGE_UNDEFINED = "undefined";
        inline static const char *LANGUAGE_ENGLISH = "en";
        inline static const char *LANGUAGE_BAHASA = "id";
    };

    struct fromEnum
    {
        static const char *toString(const ENUM &languageEnum)
        {
            const char *result = CODE::LANGUAGE_UNDEFINED;

            switch (languageEnum)
            {
                case ENUM::LANGUAGE_ENGLISH: { result = CODE::LANGUAGE_ENGLISH; } break;
                case ENUM::LANGUAGE_BAHASA: { result = CODE::LANGUAGE_BAHASA; } break;
                default: { result = CODE::LANGUAGE_ENGLISH; } break;
            }

            return result;
        }
    };
};

} // namespace libprge

#endif // LIBPRGE_LANGUAGE_ENUMS_HH
