#ifndef LIBPRGE_CORE_ACTIVE_SCENE_HH
#define LIBPRGE_CORE_ACTIVE_SCENE_HH
#include <libprge/libprge.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/tree.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/classes/camera2d.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/variant/transform3d.hpp>

/**
 * @brief core active scene type enum
 */
enum ECoreActiveSceneType : i32
{
    CORE_ACTIVE_SCENE_TYPE_UNDEFINED,
    CORE_ACTIVE_SCENE_TYPE_INIT,
    CORE_ACTIVE_SCENE_TYPE_MENU,
    CORE_ACTIVE_SCENE_TYPE_CONFIG,
    CORE_ACTIVE_SCENE_TYPE_GAMEPLAY,
    CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_TEST,
    CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER,
    CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER,
    CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL,
};
inline static cchar *CORE_ACTIVE_SCENE_TYPE_UNDEFINED_HINT = "Undefined"; // hint for CORE_ACTIVE_SCENE_TYPE_UNDEFINED
inline static cchar *CORE_ACTIVE_SCENE_TYPE_INIT_HINT = "Init"; // hint for CORE_ACTIVE_SCENE_TYPE_INIT
inline static cchar *CORE_ACTIVE_SCENE_TYPE_MENU_HINT = "Menu"; // hint for CORE_ACTIVE_SCENE_TYPE_MENU
inline static cchar *CORE_ACTIVE_SCENE_TYPE_CONFIG_HINT = "Config"; // hint for CORE_ACTIVE_SCENE_TYPE_CONFIG
inline static cchar *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_HINT = "Gameplay"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY
inline static cchar *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_TEST_HINT = "Gameplay Test"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_TEST
inline static cchar *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_HINT = "Gameplay Multiplayer"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER
inline static cchar *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER_HINT = "Gameplay Multiplayer Server"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER
inline static cchar *CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL_HINT = "Error/Fail"; // hint for CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL

/**
 * @brief core active scene dimension type
 */
enum ECoreActiveSceneDimensionType : i32
{
    CORE_ACTIVE_SCENE_DIMENSION_TYPE_UNDEFINED,
    CORE_ACTIVE_SCENE_DIMENSION_TYPE_2D,
    CORE_ACTIVE_SCENE_DIMENSION_TYPE_3D,
    CORE_ACTIVE_SCENE_DIMENSION_TYPE_MIX,
};
inline static cchar *CORE_ACTIVE_SCENE_DIMENSION_TYPE_UNDEFINED_HINT = "Undefined"; // hint for CORE_ACTIVE_SCENE_DIMENSION_TYPE_UNDEFINED
inline static cchar *CORE_ACTIVE_SCENE_DIMENSION_TYPE_2D_HINT = "2D"; // hint for CORE_ACTIVE_SCENE_DIMENSION_TYPE_2D
inline static cchar *CORE_ACTIVE_SCENE_DIMENSION_TYPE_3D_HINT = "3D"; // hint for CORE_ACTIVE_SCENE_DIMENSION_TYPE_3D
inline static cchar *CORE_ACTIVE_SCENE_DIMENSION_TYPE_MIX_HINT = "MIX"; // hint for CORE_ACTIVE_SCENE_DIMENSION_TYPE_MIX

/**
 * @brief libprge core active scene
 * 
 * @note use for current active scene/level only
 * @note there should be only one node under "/root" node
 * 
 * @todo - get editor camera position & rotation then store it
 * @todo - later on, user can debug their player controller from current camera position
 */
class CCoreActiveScene : public Node
{
    GDCLASS(CCoreActiveScene, Node);
private:
    ECoreActiveSceneType m_sceneType; // private: current scene type

    Ref<PackedScene> m_sceneNext; // private: scene next data storage, involve with initSceneNextInGame function

    ECoreActiveSceneDimensionType m_sceneDimension; // private: scene dimension, mostly for gameplay info

    Array m_rootNodesToAdd; // private: array object node scene to add under "/root", there's no sanity check, duplicated node may exists

protected:
    static void _bind_methods();

public:
    CCoreActiveScene(/* args */);
    ~CCoreActiveScene();

    //////////////////////////////////////////////////////

    /**
     * @brief set current scene type
     * 
     * @param sceneTypeEnum 
     */
    void                 setSceneType(ECoreActiveSceneType sceneTypeEnum);
    /**
     * @brief get current scene type
     * 
     * @return ECoreActiveSceneType 
     */
    ECoreActiveSceneType getSceneType();

    //////////////////////////////////////////////////////

    /**
     * @brief set scene next
     * 
     * @param refNextScene 
     */
    void             setSceneNext(Ref<PackedScene> refNextScene);
    /**
     * @brief get scene next
     * 
     * @return Ref<PackedScene> 
     */
    Ref<PackedScene> getSceneNext();
    /**
     * @brief init scene next
     * 
     * @note in-game true
     */
    void             initSceneNextInGame();

    //////////////////////////////////////////////////////

    /**
     * @brief set scene dimension
     * 
     * @param sceneDimensionEnum 
     */
    void                          setSceneDimension(ECoreActiveSceneDimensionType sceneDimensionEnum);
    /**
     * @brief get scene dimension
     * 
     * @return ECoreActiveSceneDimensionType 
     */
    ECoreActiveSceneDimensionType getSceneDimension();

    //////////////////////////////////////////////////////

    /**
     * @brief set root nodes to add
     * 
     * @param nodesToAdd 
     */
    void  setRootNodesToAdd(Array nodesToAdd);
    /**
     * @brief get root nodes to add
     * 
     * @return Array 
     */
    Array getRootNodesToAdd();
    /**
     * @brief init root nodes to add
     * 
     * @note apply if m_rootNodesToAdd not empty
     */
    void  initRootNodesToAddInGame();

    //////////////////////////////////////////////////////

    /**
     * @brief tell if this is a CCoreActiveScene class
     * 
     * @return true 
     * @return false 
     */
    bool isCCoreActiveScene() { return true; }

    //////////////////////////////////////////////////////

    /**
     * @brief set active scene to sceneFilePath param
     * 
     * @param sceneFilePath 
     */
    void setActiveScene(String sceneFilePath);

    //////////////////////////////////////////////////////

    /**
     * @brief get current active scene file
     * 
     * @return String 
     */
    String getActiveSceneFile();

    //////////////////////////////////////////////////////

    /**
     * @brief get current active scene file path
     * 
     * @return String 
     */
    String getActiveSceneFilePath();

    //////////////////////////////////////////////////////

    /**
     * @brief get current active scene file name only without extension
     * 
     * @return String 
     */
    String getActiveSceneFileNameOnly();

    //////////////////////////////////////////////////////

    /**
     * @brief exit game or app
     */
    void exitGameOrApp();
};

// default class name for CCoreActiveScene
inline static cchar *CCoreActiveScene_CLASS = "CCoreActiveScene";

// signal sceneType changed for CCoreActiveScene
inline static cchar *CCoreActiveSceneSignals_sceneType_changed = "sceneType_changed";

#endif // LIBPRGE_CORE_ACTIVE_SCENE_HH
