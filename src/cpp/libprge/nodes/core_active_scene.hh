#ifndef LIBPRGE_CORE_ACTIVE_SCENE_HH
#define LIBPRGE_CORE_ACTIVE_SCENE_HH
#include <libprge/libprge.hh>

#include <godot_cpp/classes/node.hpp>

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
    CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER,
    CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER,
    CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL,
};
inline static const char *CORE_ACTIVE_SCENE_TYPE_UNDEFINED_HINT = "Undefined"; // hint for CORE_ACTIVE_SCENE_TYPE_UNDEFINED
inline static const char *CORE_ACTIVE_SCENE_TYPE_INIT_HINT = "Init"; // hint for CORE_ACTIVE_SCENE_TYPE_INIT
inline static const char *CORE_ACTIVE_SCENE_TYPE_MENU_HINT = "Menu"; // hint for CORE_ACTIVE_SCENE_TYPE_MENU
inline static const char *CORE_ACTIVE_SCENE_TYPE_CONFIG_HINT = "Config"; // hint for CORE_ACTIVE_SCENE_TYPE_CONFIG
inline static const char *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_HINT = "Gameplay"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY
inline static const char *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_HINT = "Gameplay Multiplayer"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER
inline static const char *CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER_HINT = "Gameplay Multiplayer Server"; // hint for CORE_ACTIVE_SCENE_TYPE_GAMEPLAY_MULTIPLAYER_SERVER
inline static const char *CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL_HINT = "Error/Fail"; // hint for CORE_ACTIVE_SCENE_TYPE_ERROR_OR_FAIL

inline static const char *CCoreActiveSceneSignals_sceneType_changed = "sceneType_changed";

/**
 * @brief libprge core active scene
 * 
 * @note use for current active scene/level only
 * @note there should be only one node under "/root" node
 */
class CCoreActiveScene : public Node
{
    GDCLASS(CCoreActiveScene, Node);
private:
    ECoreActiveSceneType m_sceneType; // current scene type

protected:
    static void _bind_methods();

public:
    CCoreActiveScene(/* args */);
    ~CCoreActiveScene();

    /**
     * @brief set current scene type
     * 
     * @param sceneTypeEnum ECoreActiveSceneType
     */
    void                 setSceneType(ECoreActiveSceneType sceneTypeEnum);
    /**
     * @brief get current scene type
     * 
     * @return ECoreActiveSceneType 
     */
    ECoreActiveSceneType getSceneType();

    /**
     * @brief set active scene to sceneFilePath param
     * 
     * @param sceneFilePath 
     */
    void setActiveScene(String sceneFilePath);
    /**
     * @brief get current active scene file
     * 
     * @return String 
     */
    String getActiveSceneFile();
    /**
     * @brief get current active scene file path
     * 
     * @return String 
     */
    String getActiveSceneFilePath();
    /**
     * @brief get current active scene file name only without extension
     * 
     * @return String 
     */
    String getActiveSceneFileNameOnly();
};

// default class name for CCoreActiveScene
inline static const char *CCoreActiveScene_CLASS = "CCoreActiveScene";

#endif // LIBPRGE_CORE_ACTIVE_SCENE_HH
