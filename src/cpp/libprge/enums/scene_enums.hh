#ifndef LIBPRGE_SCENE_ENUMS_HH
#define LIBPRGE_SCENE_ENUMS_HH
#include <libprge/base/config.hh>

#include <godot_cpp/core/binder_common.hpp>

namespace libprge
{

/**
 * @brief scene type enum structure
 */
struct ESceneType
{
    enum ENUM : i32
    {
        SCENE_TYPE_UNDEFINED,
        SCENE_TYPE_MENU,
        SCENE_TYPE_GAMEPLAY,
        SCENE_TYPE_INITIALIZE,
        SCENE_TYPE_CHECK_GAME_MODULES,
        SCENE_TYPE_VERIFY_APPORGAME_PRODUCT,
        SCENE_TYPE_BAD_APPORGAME_ORIGINALITY,
        SCENE_TYPE_ERROR_OR_VIOLATION,
    };

    struct CODE
    {
        inline static const char *SCENE_TYPE_UNDEFINED = "Undefined";
        inline static const char *SCENE_TYPE_MENU = "Menu";
        inline static const char *SCENE_TYPE_GAMEPLAY = "Gameplay";
        inline static const char *SCENE_TYPE_INITIALIZE = "Initialize";
        inline static const char *SCENE_TYPE_CHECK_GAME_MODULES = "Check";
        inline static const char *SCENE_TYPE_VERIFY_APPORGAME_PRODUCT = "Verifying App/Game Product";
        inline static const char *SCENE_TYPE_BAD_APPORGAME_ORIGINALITY = "Bad App/Game Originality";
        inline static const char *SCENE_TYPE_ERROR_OR_VIOLATION = "Error/Violation";
    };

    struct fromEnum
    {
        static const char *toString(const ENUM &enumPar)
        {
            const char *result = CODE::SCENE_TYPE_UNDEFINED;

            switch (enumPar)
            {
                case ENUM::SCENE_TYPE_MENU: { result = CODE::SCENE_TYPE_MENU; } break;
                case ENUM::SCENE_TYPE_GAMEPLAY: { result = CODE::SCENE_TYPE_GAMEPLAY; } break;
                case ENUM::SCENE_TYPE_INITIALIZE: { result = CODE::SCENE_TYPE_INITIALIZE; } break;
                case ENUM::SCENE_TYPE_CHECK_GAME_MODULES: { result = CODE::SCENE_TYPE_CHECK_GAME_MODULES; } break;
                case ENUM::SCENE_TYPE_VERIFY_APPORGAME_PRODUCT: { result = CODE::SCENE_TYPE_VERIFY_APPORGAME_PRODUCT; } break;
                case ENUM::SCENE_TYPE_BAD_APPORGAME_ORIGINALITY: { result = CODE::SCENE_TYPE_BAD_APPORGAME_ORIGINALITY; } break;
                case ENUM::SCENE_TYPE_ERROR_OR_VIOLATION: { result = CODE::SCENE_TYPE_ERROR_OR_VIOLATION; } break;
                default: { result = CODE::SCENE_TYPE_UNDEFINED; } break;
            }

            return result;
        }
    };
};

} // namespace libprge

#endif // LIBPRGE_SCENE_ENUMS_HH
