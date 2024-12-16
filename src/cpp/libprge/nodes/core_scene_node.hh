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

    bool             m_onInitAddCoreGameNode = false;
    i32              m_coreGameNodeSceneFileError = 0;
    Ref<PackedScene> m_coreGameNodeSceneFile = Ref<PackedScene>();

protected:
    static void _bind_methods();

public:
    CCoreSceneNode(/* args */);
    ~CCoreSceneNode();

    void       setSceneType(SCENE_TYPE sceneType) { m_sceneType = sceneType; }
    SCENE_TYPE getSceneType() { return m_sceneType; }

    void   setActiveSceneTo(String sceneFilePath) { IScene.setActiveSceneTo(this, sceneFilePath); }

    String getSceneAsFilePath() { return IScene.getSceneAsFilePath(this); }
    String getSceneAsFileName() { return IScene.getSceneAsFileName(this); }

    void setOnInitAddCoreGameNode(bool trueOrFalse) { m_onInitAddCoreGameNode = trueOrFalse; }
    bool getOnInitAddCoreGameNode() { return m_onInitAddCoreGameNode; }

    void   setCoreGameSceneFile(Ref<PackedScene> coreGameNodeSceneFile)
    {
        if (coreGameNodeSceneFile.is_valid()) { m_coreGameNodeSceneFile = coreGameNodeSceneFile; }
        else { logger::log::errorAlways("CCoreGameNodeNode param for scene file is null"); }
    }
    Ref<PackedScene> getCoreGameSceneFile()
    {
        if (!m_coreGameNodeSceneFile.is_valid() && m_coreGameNodeSceneFileError <= 0) { m_coreGameNodeSceneFileError++; logger::log::errorAlways("CCoreGameNodeNode scene file is null"); }
        return m_coreGameNodeSceneFile;
    }

    void _ready();

#pragma region required interface in-game implementation
    void onReadyInGameRT();

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
