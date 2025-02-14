#include <libprge/config.hh>


namespace libprge
{

void initialize(ModuleInitializationLevel pLevel)
{
    if (pLevel != MODULE_INITIALIZATION_LEVEL_SCENE) { return; }

    ///////////////////////////////////////////////////////////////

    // create core libprge dirs

    ///////////////////////////////////////////////////////////////

    // auto pEngine = Engine::get_singleton();

    ///////////////////////////////////////////////////////////////

    // GDREGISTER_CLASS(CConsoleObj);
    // if (!pConsole) { pConsole = memnew(CConsoleObj); }
    // pEngine->register_singleton(CConsoleObj_CLASS, pConsole);

    ///////////////////////////////////////////////////////////////

    // CConsoleObj::log("libprge initialized");
}

void terminateAndExit(ModuleInitializationLevel pLevel)
{
    if (pLevel != MODULE_INITIALIZATION_LEVEL_SCENE) { return; }

    ///////////////////////////////////////////////////////////////

    // auto pEngine = Engine::get_singleton();

    ///////////////////////////////////////////////////////////////

    // if (pConsole) { memdelete(pConsole); }
    // pEngine->unregister_singleton(CConsoleObj_CLASS);

    ///////////////////////////////////////////////////////////////

    // CConsoleObj::log("libprge terminated");
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
