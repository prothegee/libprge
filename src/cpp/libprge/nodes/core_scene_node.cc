#include "core_scene_node.hh"

#include "core_game_node.hh"
#include "core_player_node.hh"

VARIANT_ENUM_CAST(libprge::SCENE_TYPE);

namespace libprge
{

void CCoreSceneNode::_bind_methods()
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

        ClassDB::bind_method(D_METHOD("setSceneType", "sceneType"), &CCoreSceneNode::setSceneType);
        ClassDB::bind_method(D_METHOD("getSceneType"), &CCoreSceneNode::getSceneType);
        ClassDB::add_property(CCoreSceneNode_CLASS, PropertyInfo(
            Variant::Type::INT, "info_sceneType",
            PropertyHint::PROPERTY_HINT_ENUM, sceneType
        ), "setSceneType", "getSceneType");
    }

    // IScene
    {
        ClassDB::bind_method(D_METHOD("setActiveSceneTo", "sceneFilePath"), &CCoreSceneNode::setActiveSceneTo);

        ClassDB::bind_method(D_METHOD("getSceneAsFilePath"), &CCoreSceneNode::getSceneAsFilePath);
        ClassDB::bind_method(D_METHOD("getSceneAsFileName"), &CCoreSceneNode::getSceneAsFileName);
    }

    ADD_GROUP("In Game Root", "InGameRoot_");
        ADD_SUBGROUP("Scene Initialize", "InGameRoot_SceneInitialize_");
    // in game root initialize
    {
        // core network node
        ClassDB::bind_method(D_METHOD("setOnInitAddCoreNetworkNode", "trueOrFalse"), &CCoreSceneNode::setOnInitAddCoreNetworkNode);
        ClassDB::bind_method(D_METHOD("getOnInitAddCoreNetworkNode"), &CCoreSceneNode::getOnInitAddCoreNetworkNode);
        ClassDB::add_property(CCoreSceneNode_CLASS, PropertyInfo(
            Variant::Type::BOOL, "InGameRoot_SceneInitialize_addCoreNetwork"
        ), "setOnInitAddCoreNetworkNode", "getOnInitAddCoreNetworkNode");

        // core game node
        ClassDB::bind_method(D_METHOD("setOnInitAddCoreGameNode", "trueOrFalse"), &CCoreSceneNode::setOnInitAddCoreGameNode);
        ClassDB::bind_method(D_METHOD("getOnInitAddCoreGameNode"), &CCoreSceneNode::getOnInitAddCoreGameNode);
        ClassDB::add_property(CCoreSceneNode_CLASS, PropertyInfo(
            Variant::Type::BOOL, "InGameRoot_SceneInitialize_addCoreGame"
        ), "setOnInitAddCoreGameNode", "getOnInitAddCoreGameNode");

        ClassDB::bind_method(D_METHOD("setOnInitCoreGameSceneFile", "coreGameNodeSceneFile"), &CCoreSceneNode::setOnInitCoreGameSceneFile);
        ClassDB::bind_method(D_METHOD("getOnInitCoreGameSceneFile"), &CCoreSceneNode::getOnInitCoreGameSceneFile);
        ClassDB::add_property(CCoreSceneNode_CLASS, PropertyInfo(
            Variant::Type::OBJECT, "InGameRoot_SceneInitialize_coreGameNodeFile"
        ), "setOnInitCoreGameSceneFile", "getOnInitCoreGameSceneFile");

        // core player node
        ClassDB::bind_method(D_METHOD("setOnInitAddCorePlayerNode", "trueOrFalse"), &CCoreSceneNode::setOnInitAddCorePlayerNode);
        ClassDB::bind_method(D_METHOD("getOnInitAddCorePlayerNode"), &CCoreSceneNode::getOnInitAddCorePlayerNode);
        ClassDB::add_property(CCoreSceneNode_CLASS, PropertyInfo(
            Variant::Type::BOOL, "InGameRoot_SceneInitialize_addCorePlayer"
        ), "setOnInitAddCorePlayerNode", "getOnInitAddCorePlayerNode");

        // next scene file
        ClassDB::bind_method(D_METHOD("setOnInitNextSceneFile", "nextSceneFile"), &CCoreSceneNode::setOnInitNextSceneFile);
        ClassDB::bind_method(D_METHOD("getOnInitNextSceneFile"), &CCoreSceneNode::getOnInitNextSceneFile);
        ClassDB::add_property(CCoreSceneNode_CLASS, PropertyInfo(
            Variant::Type::OBJECT, "InGameRoot_SceneInitialize_nextScene"
        ), "setOnInitNextSceneFile", "getOnInitNextSceneFile");
    }

    // virtual functions/methods
    // in-game
    {
        BIND_VIRTUAL_METHOD(CCoreSceneNode, onReadyInGameRT);
        BIND_VIRTUAL_METHOD(CCoreSceneNode, onProcessInGameRT);
        BIND_VIRTUAL_METHOD(CCoreSceneNode, onPhysicsProcessInGameRT);
    }
    // in-editor
    {
        BIND_VIRTUAL_METHOD(CCoreSceneNode, onReadyInEditorRT);
        BIND_VIRTUAL_METHOD(CCoreSceneNode, onProcessInEditorRT);
        BIND_VIRTUAL_METHOD(CCoreSceneNode, onPhysicsProcessInEditorRT);
    }
}

CCoreSceneNode::CCoreSceneNode()
{
    // lastly
    this->set_name(m_defaultName);
}

CCoreSceneNode::~CCoreSceneNode()
{
}

void CCoreSceneNode::_ready()
{
    if (!Engine::get_singleton()->is_editor_hint())
    {
        logger::log::debug("current scene:\n- name: \"", pIScene->getSceneAsFileName(this), "\"\n- file path: \"", pIScene->getSceneAsFilePath(this), "\"");
        onReadyInGameRT();
    }

    if (Engine::get_singleton()->is_editor_hint())
    {
        // reservedd
    }
}

void CCoreSceneNode::_input(const Ref<InputEvent> &pEvent)
{
    if (!Engine::get_singleton()->is_editor_hint())
    {
        onInputInGameRT(pEvent);
    }
}

void CCoreSceneNode::onInputInGameRT(const Ref<InputEvent> &pEvent)
{
    /* NOT IMPLEMENTED */
}

#pragma region required interface implementation
void CCoreSceneNode::onReadyInGameRT()
{
    // core network node
    if (getOnInitAddCoreNetworkNode())
    {
        if (m_sceneType != SCENE_TYPE_INITIALIZE) { return; }

        logger::log::debug("TODO: add CCoreNetworkNode");
    }

    // core game node
    if (getOnInitAddCoreGameNode())
    {
        if (m_sceneType != SCENE_TYPE_INITIALIZE) { return; }

        // reference pointer scene of CoreGameNode
        auto rpCoreGameNode = getOnInitCoreGameSceneFile();
        // reference pointer next scene for on init type
        auto rpOnInitNextScene = getOnInitNextSceneFile();

        if (rpCoreGameNode.is_null())
        {
            logger::log::errorAlways("Initialize scene using add CCoreGameNode class, but the file is null");
            return;
        }

        if (rpCoreGameNode.ptr()->instantiate()->get_class() != CCoreGameNode_CLASS)
        {
            logger::log::errorAlways("Initialize scene using add CCoreGameNode class, but the class type is not match");
            return;
        }

        // create & add child on root node since it valid/exists
        auto pCoreGameNode = (CCoreGameNode*)rpCoreGameNode.ptr()->instantiate();
        pIRootNode->addChild(this, pCoreGameNode);

        if (!rpOnInitNextScene.is_null())
        {
            logger::log::debug("using next scene since next scene on init is true & valid");
            pIScene->setActiveSceneTo(this, rpOnInitNextScene.ptr()->get_path());
        }
    }

    // core player node
    if (getOnInitAddCorePlayerNode())
    {
        if (m_sceneType != SCENE_TYPE_INITIALIZE) { return; }

        auto pCorePlayer = memnew(CCorePlayerNode);

        pIRootNode->addChild(this, pCorePlayer);
    }
}

void CCoreSceneNode::onProcessInGameRT()
{
    /* NOT IMPLEMENTED */
}

void CCoreSceneNode::onPhysicsProcessInGameRT()
{
    /* NOT IMPLEMENTED */
}
#pragma endregion

void CCoreSceneNode::onReadyInEditorRT()
{
    /* NOT IMPLEMENTED */
}

void CCoreSceneNode::onProcessInEditorRT()
{
    /* NOT IMPLEMENTED */
}

void CCoreSceneNode::onPhysicsProcessInEditorRT()
{
    /* NOT IMPLEMENTED */
}

} // namespace libprge
