#include "core_scene.hh"

VARIANT_ENUM_CAST(libprge::SCENE_TYPE);

namespace libprge
{

void CCoreScene::_bind_methods()
{
    ADD_GROUP("Info", "info_");
    // scene enum
    {
        String sceneType;

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCEN_TYPE_UNDEFINED);
        sceneType += SCENE_CODE::SCENE_TYPE_UNDEFINED;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_MENU);
        sceneType += SCENE_CODE::SCENE_TYPE_MENU;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_GAMEPLAY);
        sceneType += SCENE_CODE::SCENE_TYPE_GAMEPLAY;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_INITIALIZE);
        sceneType += SCENE_CODE::SCENE_TYPE_INITIALIZE;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_CHECK_GAME_MODULES);
        sceneType += SCENE_CODE::SCENE_TYPE_CHECK_GAME_MODULES;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_VERIFY_APPORGAME_PRODUCT);
        sceneType += SCENE_CODE::SCENE_TYPE_VERIFY_APPORGAME_PRODUCT;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_BAD_APPORGAME_ORIGINALITY);
        sceneType += SCENE_CODE::SCENE_TYPE_BAD_APPORGAME_ORIGINALITY;
            sceneType += ",";

        BIND_ENUM_CONSTANT(SCENE_TYPE::SCENE_TYPE_ERROR_OR_VIOLATION);
        sceneType += SCENE_CODE::SCENE_TYPE_ERROR_OR_VIOLATION;
            sceneType += "";

        ClassDB::bind_method(D_METHOD("setSceneType", "sceneType"), &CCoreScene::setSceneType);
        ClassDB::bind_method(D_METHOD("getSceneType"), &CCoreScene::getSceneType);
        ClassDB::add_property(CCORESCENE_CLASS, PropertyInfo(
            Variant::Type::INT, "info_sceneType",
            PropertyHint::PROPERTY_HINT_ENUM, sceneType
        ), "setSceneType", "getSceneType");
    }

    // IScene
    {
        ClassDB::bind_method(D_METHOD("setActiveSceneTo", "sceneFilePath"), &CCoreScene::setActiveSceneTo);

        ClassDB::bind_method(D_METHOD("getSceneAsFilePath"), &CCoreScene::getSceneAsFilePath);
        ClassDB::bind_method(D_METHOD("getSceneAsFileName"), &CCoreScene::getSceneAsFileName);
    }

    ADD_GROUP("In Game Root", "InGameRoot_");
        ADD_SUBGROUP("Scene Initialize", "InGameRoot_SceneInitialize_");
    // in game root invoke core game
    {
        ClassDB::bind_method(D_METHOD("setOnInitAddCoreGameNode", "trueOrFalse"), &CCoreScene::setOnInitAddCoreGameNode);
        ClassDB::bind_method(D_METHOD("getOnInitAddCoreGameNode"), &CCoreScene::getOnInitAddCoreGameNode);
        ClassDB::add_property(CCORESCENE_CLASS, PropertyInfo(
            Variant::Type::BOOL, "InGameRoot_SceneInitialize_addCoreGame"
        ), "setOnInitAddCoreGameNode", "getOnInitAddCoreGameNode");
    }

    // virtual functions/methods
    // in-game
    {
        BIND_VIRTUAL_METHOD(CCoreScene, onReadyInGameRT);
        BIND_VIRTUAL_METHOD(CCoreScene, onProcessInGameRT);
        BIND_VIRTUAL_METHOD(CCoreScene, onPhysicsProcessInGameRT);
    }
    // in-editor
    {
        BIND_VIRTUAL_METHOD(CCoreScene, onReadyInEditorRT);
        BIND_VIRTUAL_METHOD(CCoreScene, onProcessInEditorRT);
        BIND_VIRTUAL_METHOD(CCoreScene, onPhysicsProcessInEditorRT);
    }
}

CCoreScene::CCoreScene()
{
    // lastly
    this->set_name(m_defaultName);
}

CCoreScene::~CCoreScene()
{
}

void CCoreScene::_ready()
{
    if (!Engine::get_singleton()->is_editor_hint())
    {
        onReadyInGameRT();
    }

    if (Engine::get_singleton()->is_editor_hint())
    {
        // reserved
    }
}

#pragma region required interface implementation
void CCoreScene::onReadyInGameRT()
{
    if (getOnInitAddCoreGameNode())
    {
        logger::log::debug("TODO IN-GAME: add CCoreGame node under \"/root\" node");
    }
}

void CCoreScene::onProcessInGameRT()
{
    /* NOT IMPLEMENTED*/
}

void CCoreScene::onPhysicsProcessInGameRT()
{
    /* NOT IMPLEMENTED*/
}
#pragma endregion

void CCoreScene::onReadyInEditorRT()
{
    /* NOT IMPLEMENTED*/
}

void CCoreScene::onProcessInEditorRT()
{
    /* NOT IMPLEMENTED*/
}

void CCoreScene::onPhysicsProcessInEditorRT()
{
    /* NOT IMPLEMENTED*/
}

} // namespace libprge
