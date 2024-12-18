#ifndef LIBPRGE_CORE_SCENE_NODE_HH
#define LIBPRGE_CORE_SCENE_NODE_HH
#include <libprge/base/config.hh>
#include <libprge/enums/scene_enums.hh>
#include <libprge/interfaces/iscene_controller.hh>
#include <libprge/interfaces/iin_game_controller.hh>
#include <libprge/interfaces/iin_editor_controller.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/scene_multiplayer.hpp>
#include <godot_cpp/classes/scene_replication_config.hpp>
#include <godot_cpp/classes/scene_state.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/scene_tree_timer.hpp>
#include <godot_cpp/core/binder_common.hpp>

namespace libprge
{

using namespace godot;

// replacement enum scene for CCoreSceneNode
enum SCENE_TYPE : i32
{
    SCEN_TYPE_UNDEFINED = ESceneType::ENUM::SCENE_TYPE_UNDEFINED,
    SCENE_TYPE_MENU = ESceneType::ENUM::SCENE_TYPE_MENU,
    SCENE_TYPE_GAMEPLAY = ESceneType::ENUM::SCENE_TYPE_GAMEPLAY,
    SCENE_TYPE_INITIALIZE = ESceneType::ENUM::SCENE_TYPE_INITIALIZE,
    SCENE_TYPE_CHECK_GAME_MODULES = ESceneType::ENUM::SCENE_TYPE_CHECK_GAME_MODULES,
    SCENE_TYPE_VERIFY_APPORGAME_PRODUCT = ESceneType::ENUM::SCENE_TYPE_VERIFY_APPORGAME_PRODUCT,
    SCENE_TYPE_BAD_APPORGAME_ORIGINALITY = ESceneType::ENUM::SCENE_TYPE_BAD_APPORGAME_ORIGINALITY,
    SCENE_TYPE_ERROR_OR_VIOLATION = ESceneType::ENUM::SCENE_TYPE_ERROR_OR_VIOLATION,
};

// replacement code scene for CCoreSceneNode
struct SCENE_CODE : public ESceneType::CODE
{
    // RESERVED
};

static const char *CCoreSceneNode_CLASS = "CCoreSceneNode";
static const char *CCoreSceneNode_BRIEF = R"(class CCoreSceneNode final
* @brief libprge core scene node class
)";

/**
 * @brief libprge core scene node class
 */
class CCoreSceneNode : public Node
                     , public ISceneController
                     , public IInGameController
                     , public IInEditorController
{
    GDCLASS(CCoreSceneNode, Node);
private:
    const String m_defaultName = "core-scene";

    SCENE_TYPE m_sceneType = SCENE_TYPE::SCEN_TYPE_UNDEFINED;

    bool             m_onInitCoreNetworkNodeAdd = false;
    // i32              m_onInitCoreNetworkNodeSceneFileError = 0;
    // Ref<PackedScene> m_onInitCoreNetworkNodeSceneFile = Ref<PackedScene>();

    bool             m_onInitCoreGameNodeAdd = false;
    i32              m_onInitCoreGameNodeSceneFileError = 0;
    Ref<PackedScene> m_onInitCoreGameNodeSceneFile = Ref<PackedScene>();

    bool             m_onInitCorePlayerNodeAdd = false;
    // i32              m_onInitCorePlayerNodeSceneFileError = 0;
    // Ref<PackedScene> m_onInitCorePlayerNodeSceneFile = Ref<PackedScene>();

    i32              m_onInitNextSceneFileError = 0;
    Ref<PackedScene> m_onInitNextScene = Ref<PackedScene>();

protected:
    static void _bind_methods();

public:
    CCoreSceneNode(/* args */);
    ~CCoreSceneNode();

    void       setSceneType(SCENE_TYPE sceneType) { m_sceneType = sceneType; }
    SCENE_TYPE getSceneType() { return m_sceneType; }

    void   setActiveSceneTo(String sceneFilePath) { pIScene->setActiveSceneTo(this, sceneFilePath); }

    String getSceneAsFilePath() { return pIScene->getSceneAsFilePath(this); }
    String getSceneAsFileName() { return pIScene->getSceneAsFileName(this); }

#pragma region scene type on initialize
    void setOnInitAddCoreNetworkNode(bool trueOrFalse) { m_onInitCoreNetworkNodeAdd = trueOrFalse; }
    bool getOnInitAddCoreNetworkNode() { return m_onInitCoreNetworkNodeAdd; }

    void             setOnInitAddCoreGameNode(bool trueOrFalse) { m_onInitCoreGameNodeAdd = trueOrFalse; }
    bool             getOnInitAddCoreGameNode() { return m_onInitCoreGameNodeAdd; }
    void             setOnInitCoreGameSceneFile(Ref<PackedScene> coreGameNodeSceneFile) 
    {
        if (coreGameNodeSceneFile.is_valid())
        {
            m_onInitCoreGameNodeSceneFile = coreGameNodeSceneFile;
        }
        else
        {
            logger::log::errorAlways("CCoreGameNodeNode param for scene file is null from \"", this->get_name(), "\" of ", this->get_class(), " class!");
        }
    }
    Ref<PackedScene> getOnInitCoreGameSceneFile()
    {
        if (!m_onInitCoreGameNodeSceneFile.is_valid() && m_onInitCoreGameNodeSceneFile.is_null() && m_onInitCoreGameNodeSceneFileError <= 0)
        {
            m_onInitCoreGameNodeSceneFileError++; logger::log::warningAlways("NOTICE AT FIRST TIME ONLY\nCCoreGameNodeNode scene file is null from \"", this->get_name(), "\" of ", this->get_class(), " class!\nYou can ignore this warning for the first time");
        }
        return m_onInitCoreGameNodeSceneFile;
    }

    void setOnInitAddCorePlayerNode(bool trueOrFalse) { m_onInitCorePlayerNodeAdd = trueOrFalse; }
    bool getOnInitAddCorePlayerNode() { return m_onInitCorePlayerNodeAdd; }

    void             setOnInitNextSceneFile(Ref<PackedScene> nextSceneOnInit)
    {
        if (nextSceneOnInit.is_valid())
        {
            m_onInitNextScene = nextSceneOnInit;
        }
        else
        {
            logger::log::errorAlways("CCoreGameNodeNode param for next scene file is null from \"", this->get_name(), "\" of ", this->get_class(), " class!");
        }
    }
    Ref<PackedScene> getOnInitNextSceneFile()
    {
        if (!m_onInitNextScene.is_valid() && m_onInitNextScene.is_null() && m_onInitNextSceneFileError <= 0)
        {
            m_onInitNextSceneFileError++; logger::log::warningAlways("NOTICE AT FIRST TIME ONLY\nCCoreGameNodeNode next scene file is null from \"", this->get_name(), "\" of ", this->get_class(), " class!\nYou can ignore this warning for the first time");
        }
        return m_onInitNextScene;
    }
#pragma endregion

    void _ready();

    void _input(const Ref<InputEvent> &pEvent);

#pragma region required interface in-game implementation
    void onReadyInGameRT();

    /* NOT IMPLEMENTED */
    void onInputInGameRT(const Ref<InputEvent> &pEvent);

    /* NOT IMPLEMENTED */
    void onProcessInGameRT();

    /* NOT IMPLEMENTED */
    void onPhysicsProcessInGameRT();
#pragma endregion

#pragma region required interface in-editor implementation
    /* NOT IMPLEMENTED */
    void onReadyInEditorRT();

    /* NOT IMPLEMENTED */
    void onProcessInEditorRT();

    /* NOT IMPLEMENTED */
    void onPhysicsProcessInEditorRT();
#pragma endregion
};

} // namespace libprge

#endif // LIBPRGE_CORE_SCENE_NODE_HH
