#include "libprge.hh"

#include <libprge/functions/logger_funcs.hh>

#include <libprge/libprge.hh>
#include <libprge/nodes/core_game_node.hh>
#include <libprge/nodes/core_network_node.hh>
#include <libprge/nodes/core_player_node.hh>
#include <libprge/nodes/core_scene_node.hh>

using namespace godot;

namespace libprge
{

void initialize(ModuleInitializationLevel pLevel)
{
    switch (pLevel)
    {
        case MODULE_INITIALIZATION_LEVEL_CORE:
        {
            logger::log::message("core module initialized");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_SERVERS:
        {
        #pragma region sdks
        #pragma endregion

            logger::log::message("server module initialized");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_SCENE:
        {
        #pragma region object
        #pragma endregion

        #pragma region virtual
            // GDREGISTER_VIRTUAL_CLASS(IInGameController);
            // GDREGISTER_VIRTUAL_CLASS(IInEditorController);
            // GDREGISTER_VIRTUAL_CLASS(ISceneController);
        #pragma endregion

        #pragma region nodes
            GDREGISTER_CLASS(CCoreGameNode);
            GDREGISTER_CLASS(CCoreNetworkNode);
            GDREGISTER_CLASS(CCorePlayerNode);
            GDREGISTER_CLASS(CCoreSceneNode);
        #pragma endregion

        #pragma region nodes2d
        #pragma endregion

        #pragma region nodes3d
        #pragma endregion

        #pragma region nodesui
        #pragma endregion

            GDREGISTER_CLASS(CLibPrGe);
                pLibPrGe = memnew(CLibPrGe);
                Engine::get_singleton()->register_singleton(CLibPrGe_CLASS, pLibPrGe);

            logger::log::message("scene module initialized");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_EDITOR:
        {
            logger::log::message("editor module initialized");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_MAX:
        {
            logger::log::message("max module initialized");
        }
        break;

        default:
        {
            logger::log::message("default module initialized");
        }
        break;
    }
}

void terminateAndExit(ModuleInitializationLevel pLevel)
{
    switch (pLevel)
    {
        case MODULE_INITIALIZATION_LEVEL_CORE:
        {
            logger::log::message("core module terminated");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_SERVERS:
        {
        #pragma region region sdks
        #pragma endregion

            logger::log::message("level module terminated");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_SCENE:
        {
        #pragma region object
        #pragma endregion

        #pragma region nodes
        #pragma endregion

        #pragma region nodes2d
        #pragma endregion

        #pragma region nodes3d
        #pragma endregion

        #pragma region nodesui
        #pragma endregion

            memdelete(pLibPrGe);
            Engine::get_singleton()->unregister_singleton(CLibPrGe_CLASS);

            logger::log::message("scene module terminated");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_EDITOR:
        {
            logger::log::message("editor module terminated");
        }
        break;

        case MODULE_INITIALIZATION_LEVEL_MAX:
        {
            logger::log::message("max module terminated");
        }
        break;

        default:
        {
            logger::log::message("default module terminated");
        }
        break;
    }
}

} // namespace libprge

extern "C"
{
    // libprge runtime
    GDExtensionBool GDE_EXPORT libprge_rt(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(libprge::initialize);
        init_obj.register_terminator(libprge::terminateAndExit);

        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
