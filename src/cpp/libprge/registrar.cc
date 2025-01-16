#include "libprge.hh"

#include <libprge/nodes/core_active_scene.hh>
#include <libprge/nodes/core_local_player.hh>

#include <libprge/objects/console.hh>

namespace libprge
{

void initialize(ModuleInitializationLevel pLevel)
{
    if (pLevel != MODULE_INITIALIZATION_LEVEL_SCENE) { return; }

    GDREGISTER_CLASS(CCoreActiveScene);
    GDREGISTER_CLASS(CCoreLocalPlayer);

    GDREGISTER_CLASS(console);
    if (!pConsole) { pConsole = memnew(console); }
    Engine::get_singleton()->register_singleton(console_CLASS, pConsole);

    console::log("libprge initialized");
}

void terminateAndExit(ModuleInitializationLevel pLevel)
{
    if (pLevel != MODULE_INITIALIZATION_LEVEL_SCENE) { return; }

    if (pConsole) { memdelete(pConsole); }
    Engine::get_singleton()->unregister_singleton(console_CLASS);

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
