#include "core_active_scene.hh"

VARIANT_ENUM_CAST(ECoreActiveSceneType);
VARIANT_ENUM_CAST(ECoreActiveSceneDimensionType);

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
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_TEST);
                sceneType += CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_TEST_HINT;
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

        ClassDB::bind_method(D_METHOD("setSceneNext", "refNextScene"), &CCoreActiveScene::setSceneNext);
        ClassDB::bind_method(D_METHOD("getSceneNext"), &CCoreActiveScene::getSceneNext);
        ClassDB::add_property(CCoreActiveScene_CLASS, PropertyInfo(
            Variant::Type::OBJECT, "m_sceneNext"
        ), "setSceneNext", "getSceneNext");
        ClassDB::bind_method(D_METHOD("initSceneNextInGame"), &CCoreActiveScene::initSceneNextInGame);

        String sceneDimension;
        ClassDB::bind_method(D_METHOD("setSceneDimension", "sceneDimensionEnum"), &CCoreActiveScene::setSceneDimension);
        ClassDB::bind_method(D_METHOD("getSceneDimension"), &CCoreActiveScene::getSceneDimension);
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_DIMENSION_TYPE_UNDEFINED);
                sceneDimension += CORE_ACTIVE_SCENE_DIMENSION_TYPE_UNDEFINED_HINT;
                sceneDimension += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_DIMENSION_TYPE_2D);
                sceneDimension += CORE_ACTIVE_SCENE_DIMENSION_TYPE_2D_HINT;
                sceneDimension += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_DIMENSION_TYPE_3D);
                sceneDimension += CORE_ACTIVE_SCENE_DIMENSION_TYPE_3D_HINT;
                sceneDimension += ",";
            BIND_ENUM_CONSTANT(CORE_ACTIVE_SCENE_DIMENSION_TYPE_MIX);
                sceneDimension += CORE_ACTIVE_SCENE_DIMENSION_TYPE_MIX_HINT;
                sceneDimension += "";
        ClassDB::add_property(CCoreActiveScene_CLASS, PropertyInfo(
            Variant::Type::INT, "m_sceneDimension",
            PROPERTY_HINT_ENUM, sceneDimension
        ), "setSceneDimension", "getSceneDimension");
    }

    // root
    ADD_GROUP("Root", "m_root");
    {
        ClassDB::bind_method(D_METHOD("setRootNodesToAdd", "nodesToAdd"), &CCoreActiveScene::setRootNodesToAdd);
        ClassDB::bind_method(D_METHOD("getRootNodesToAdd"), &CCoreActiveScene::getRootNodesToAdd);
        ClassDB::add_property(CCoreActiveScene_CLASS, PropertyInfo(
            Variant::Type::ARRAY, "m_rootNodesToAdd"
        ), "setRootNodesToAdd", "getRootNodesToAdd");
        ClassDB::bind_method(D_METHOD("initRootNodesToAddInGame"), &CCoreActiveScene::initRootNodesToAddInGame);
    }

    // none editor property
    {
    }

    // signals
    {
        ADD_SIGNAL(MethodInfo(CCoreActiveSceneSignals_sceneType_changed));
    }

    // extend functions
    {
        ClassDB::bind_method(D_METHOD("isCCoreActiveScene"), &CCoreActiveScene::isCCoreActiveScene);

        ClassDB::bind_method(D_METHOD("setActiveScene"), &CCoreActiveScene::setActiveScene);
        ClassDB::bind_method(D_METHOD("getActiveSceneFile"), &CCoreActiveScene::getActiveSceneFile);
        ClassDB::bind_method(D_METHOD("getActiveSceneFilePath"), &CCoreActiveScene::getActiveSceneFilePath);
        ClassDB::bind_method(D_METHOD("getActiveSceneFileNameOnly"), &CCoreActiveScene::getActiveSceneFileNameOnly);

        ClassDB::bind_method(D_METHOD("exitGameOrApp"), &CCoreActiveScene::exitGameOrApp);
    }
}

CCoreActiveScene::CCoreActiveScene()
{
    m_sceneType = CORE_ACTIVE_SCENE_TYPE_UNDEFINED;

    m_sceneNext = Ref<PackedScene>();

    m_sceneDimension = CORE_ACTIVE_SCENE_DIMENSION_TYPE_UNDEFINED;

    m_rootNodesToAdd = Array();
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

void CCoreActiveScene::setSceneNext(Ref<PackedScene> refNextScene)
{
    m_sceneNext = refNextScene;
}

Ref<PackedScene> CCoreActiveScene::getSceneNext()
{
    return m_sceneNext;
}

void CCoreActiveScene::initSceneNextInGame()
{
    if (Engine::get_singleton()->is_editor_hint()) { return; }

    if (m_sceneNext.is_null())
    {
        console::error("attempt to use initSceneNextInGame, but m_sceneNext is null");
        return;
    }

    try
    {
        auto sourceAsPath = m_sceneNext.ptr()->get_path();

        console::log_debug("\ninit scene next:\n    - scene name: ", sourceAsPath.get_file(), "\n    - scene file: ", sourceAsPath, "\n");
        get_tree()->call_deferred(GDMETHODS_CALL::CHANGE_SCENE_TO_FILE, sourceAsPath);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        console::error(e.what());
    }
}

void CCoreActiveScene::setSceneDimension(ECoreActiveSceneDimensionType sceneDimensionEnum)
{
    m_sceneDimension = sceneDimensionEnum;
}

ECoreActiveSceneDimensionType CCoreActiveScene::getSceneDimension()
{
    return m_sceneDimension;
}

void CCoreActiveScene::setRootNodesToAdd(Array nodesToAdd)
{
    m_rootNodesToAdd = nodesToAdd;
}

Array CCoreActiveScene::getRootNodesToAdd()
{
    return m_rootNodesToAdd;
}

void CCoreActiveScene::initRootNodesToAddInGame()
{
    if (Engine::get_singleton()->is_editor_hint()) { return; }

    if (m_rootNodesToAdd.is_empty())
    {
        console::error("attempt to use initRootNodesToAddInGame, but m_rootNodesToAdd is null");
        return;
    }

    auto pRoot = get_node<Node>("/root");

    auto nodesToAdd = getRootNodesToAdd();

    for (i32 i = 0; i < nodesToAdd.size(); i++)
    {
        auto pNode = nodesToAdd[i];

        if (auto resourceNode = ((Ref<PackedScene>)pNode)->instantiate())
        {
            pRoot->call_deferred(GDMETHODS_CALL::ADD_CHILD, resourceNode);
            console::log_debug("adding child under game /root: ", resourceNode->get_name(), " with ", resourceNode->get_class(), " class type");
        }
    }
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
        std::cerr << e.what() << '\n';
        console::error(e.what());
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

void CCoreActiveScene::exitGameOrApp()
{
    try
    {
        get_tree()->quit();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        console::error(e.what());
    }
}
