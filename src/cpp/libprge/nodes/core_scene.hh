#ifndef LIBPRGE_CORE_SCENE_HH
#define LIBPRGE_CORE_SCENE_HH
#include <libprge/base/config.hh>
#include <libprge/enums/scene_enums.hh>
#include <libprge/interfaces/iscene_controller.hh>
#include <libprge/interfaces/iin_game_controller.hh>
#include <libprge/interfaces/iin_editor_controller.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/binder_common.hpp>

namespace libprge
{

using namespace godot;

// replacement enum scene for CCoreScene
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

// replacement code scene for CCoreScene
struct SCENE_CODE : public ESceneType::CODE
{
    // RESERVED
};

static const char *CCORESCENE_CLASS = "CCoreScene";
static const char *CCORESCENE_BRIEF = R"(class CCoreScene final
* @brief libprge core scene node class
)";

/**
 * @brief libprge core scene node class
 */
class CCoreScene : public Node
                 , public ISceneController
                 , public IInGameController
                 , public IInEditorController
{
    GDCLASS(CCoreScene, Node);
private:
    const String m_defaultName = "core-scene";

    SCENE_TYPE m_sceneType = SCENE_TYPE::SCEN_TYPE_UNDEFINED;

    bool m_onInitAddCoreGameNode = false;

protected:
    static void _bind_methods();

public:
    CCoreScene(/* args */);
    ~CCoreScene();

    void       setSceneType(SCENE_TYPE sceneType) { m_sceneType = sceneType; }
    SCENE_TYPE getSceneType() const { return m_sceneType; }

    void   setActiveSceneTo(String sceneFilePath) { IScene.setActiveSceneTo(this, sceneFilePath); }

    String getSceneAsFilePath() { return IScene.getSceneAsFilePath(this); }
    String getSceneAsFileName() { return IScene.getSceneAsFileName(this); }

    void setOnInitAddCoreGameNode(bool trueOrFalse) { m_onInitAddCoreGameNode = trueOrFalse; }
    bool getOnInitAddCoreGameNode() { return m_onInitAddCoreGameNode; }

    void _ready();

#pragma region required interface in-game implementation
    void onReadyInGameRT();

    void onProcessInGameRT();

    void onPhysicsProcessInGameRT();
#pragma endregion

#pragma region required interface in-editor implementation
    void onReadyInEditorRT();

    void onProcessInEditorRT();

    void onPhysicsProcessInEditorRT();
#pragma endregion
};

} // namespace libprge

#endif // LIBPRGE_CORE_SCENE_HH
