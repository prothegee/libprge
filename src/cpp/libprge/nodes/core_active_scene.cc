#include "core_active_scene.hh"

VARIANT_ENUM_CAST(ECoreActiveSceneType);

#include <libprge/constants/gdmethod_const.hh>

void CCoreActiveScene::_bind_methods()
{
    // scene
    ADD_GROUP("Scene", "m_scene");
    {
        String sceneType;
        ClassDB::bind_method(D_METHOD("setSceneType", "sceneTypeEnum"), &CCoreActiveScene::setSceneType);
        ClassDB::bind_method(D_METHOD("getSceneType"), &CCoreActiveScene::getSceneType);
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_UNDEFINED);
                sceneType += CORE_ACTIVE_SCENE_TYPE_UNDEFINED_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_INIT);
                sceneType += CORE_ACTIVE_SCENE_TYPE_INIT_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_MENU);
                sceneType += CORE_ACTIVE_SCENE_TYPE_MENU_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_CONFIG);
                sceneType += CORE_ACTIVE_SCENE_TYPE_CONFIG_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_GAMEPLAY);
                sceneType += CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER);
                sceneType += CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER);
                sceneType += CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER_HINT;
                sceneType += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL);
                sceneType += CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL_HINT;
                sceneType += "";
        ClassDB::add_property(CCoreActiveScene_CLASS, PropertyInfo(
            Variant::Type::INT, "m_sceneType",
            PROPERTY_HINT_ENUM, sceneType
        ), "setSceneType", "getSceneType");
    }

    // signals
    {
        ADD_SIGNAL(MethodInfo(CCoreActiveSceneSignals_sceneType_changed));
    }

    // extend functions
    {
        ClassDB::bind_method(D_METHOD("setActiveScene"), &CCoreActiveScene::setActiveScene);
        ClassDB::bind_method(D_METHOD("getActiveSceneFile"), &CCoreActiveScene::getActiveSceneFile);
        ClassDB::bind_method(D_METHOD("getActiveSceneFilePath"), &CCoreActiveScene::getActiveSceneFilePath);
        ClassDB::bind_method(D_METHOD("getActiveSceneFileNameOnly"), &CCoreActiveScene::getActiveSceneFileNameOnly);
    }
}

CCoreActiveScene::CCoreActiveScene()
{
    m_sceneType = CORE_ACTIVE_SCENE_TYPE_UNDEFINED;
}

CCoreActiveScene::~CCoreActiveScene()
{
}

void CCoreActiveScene::setSceneType(ECoreActiveSceneType sceneTypeEnum)
{
    m_sceneType = sceneTypeEnum;
    emit_signal(CCoreActiveSceneSignals_sceneType_changed);
}

ECoreActiveSceneType CCoreActiveScene::getSceneType()
{
    return m_sceneType;
}

void CCoreActiveScene::setActiveScene(String sceneFilePath)
{
    try
    {
        console::log_debug("\nset active scene to:\n    - scene name: ", sceneFilePath.get_file(), "\n    - scene file: ", sceneFilePath, "\n");

        get_tree()->call_deferred(GDMETHODS_CALL::CHANGE_SCENE_TO_FILE, sceneFilePath);
    }
    catch(const std::exception& e)
    {
        String errExcpt = e.what();
        console::error(errExcpt);
        std::cerr << errExcpt.ascii() << '\n';
    }
}

String CCoreActiveScene::getActiveSceneFile()
{
    return get_tree()->get_current_scene()->get_scene_file_path().get_file();
}

String CCoreActiveScene::getActiveSceneFilePath()
{
    return get_tree()->get_current_scene()->get_scene_file_path();
}

String CCoreActiveScene::getActiveSceneFileNameOnly()
{
    std::string result;

    std::string tmpName = getActiveSceneFilePath().ascii().get_data();

    if (tmpName.find(".res") != std::string::npos)
    {
        utilityFunctions::find::andReplaceAll(tmpName, ".res", "");
    }

    if (tmpName.find(".scn") != std::string::npos)
    {
        utilityFunctions::find::andReplaceAll(tmpName, ".scn", "");
    }

    if (tmpName.find(".tscn") != std::string::npos)
    {
        utilityFunctions::find::andReplaceAll(tmpName, ".tscn", "");
    }

    result = tmpName.c_str();

    return String(result.c_str());
}
