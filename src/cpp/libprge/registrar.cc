#include "libprge.hh"

#include <libprge/nodes/core_game_manager.hh>
#include <libprge/nodes/core_network_manager.hh>
#include <libprge/nodes/core_local_player.hh>
#include <libprge/nodes/core_active_scene.hh>

#include <libprge/objects/console.hh>
#include <libprge/objects/cryptography.hh>

#include <godot_cpp/classes/scene_tree.hpp>

namespace libprge
{

void initialize(ModuleInitializationLevel pLevel)
{
    if (pLevel != MODULE_INITIALIZATION_LEVEL_SCENE) { return; }

    auto pEngine = Engine::get_singleton();

    GDREGISTER_CLASS(CCoreGameManager);
    GDREGISTER_CLASS(CCoreNetworkManager);
    GDREGISTER_CLASS(CCoreLocalPlayer);
    GDREGISTER_CLASS(CCoreActiveScene);

    GDREGISTER_CLASS(console);
        if (!pConsole) { pConsole = memnew(console); }
        pEngine->register_singleton(console_CLASS, pConsole);
    GDREGISTER_CLASS(CCryptography);
        if (!pCryptography) { pCryptography = memnew(CCryptography); }
        pEngine->register_singleton(CCryptography_CLASS, pCryptography);

    // create libprge res directory tmp
    for (auto dir : LIBPRGE_IMPORTANT_DIRS)
    {
        if (!DirAccess::dir_exists_absolute(dir))
        {
            DirAccess::make_dir_absolute(dir);
        }
    }

    console::log("libprge initialized");
}

void terminateAndExit(ModuleInitializationLevel pLevel)
{
    if (pLevel != MODULE_INITIALIZATION_LEVEL_SCENE) { return; }

    auto pEngine = Engine::get_singleton();

    if (pConsole) { memdelete(pConsole); }
        pEngine->unregister_singleton(console_CLASS);
    if (pCryptography) { memdelete(pCryptography); }
        pEngine->unregister_singleton(CCryptography_CLASS);

    console::log("libprge terminated");
}

} // namespace libprge

extern "C"
{
    // anapra runtime
    GDExtensionBool GDE_EXPORT libprge_rt(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(libprge::initialize);
        init_obj.register_terminator(libprge::terminateAndExit);

        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
