#ifndef LIBPRGE_CORE_LOCAL_PLAYER_NODE_HH
#define LIBPRGE_CORE_LOCAL_PLAYER_NODE_HH
#include <libprge/libprge.hh>

#include <godot_cpp/classes/node.hpp>

/**
 * @brief core local player node state enum
 */
enum ECoreLocalPlayerNodeState : i32
{
    CORE_LOCAL_PLAYER_NODE_STATE_UNDEFINED,
    CORE_LOCAL_PLAYER_NODE_STATE_LOADING,
    CORE_LOCAL_PLAYER_NODE_STATE_IN_MENU,
    CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY,
    CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_MENU,
    CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_INTERACTION,
    CORE_LOCAL_PLAYER_NODE_STATE_IN_SOMEWHERE_SINCE_NOT_SURE, // not sure? use this
};
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_UNDEFINED_HINT = "Undefined"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_UNDEFINED
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_LOADING_HINT = "Loading"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_LOADING
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_IN_MENU_HINT = "In Menu"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_IN_MENU
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_HINT = "In Gameplay"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_MENU_HINT = "In Gameplay Menu"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_MENU
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_INTERACTION_HINT = "In Gameplay Interaction"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_INTERACTION
inline static pConstChar CORE_LOCAL_PLAYER_NODE_STATE_IN_SOMEWHERE_SINCE_NOT_SURE_HINT = "In Somewhere, but not sure"; // hint for CORE_LOCAL_PLAYER_NODE_STATE_IN_SOMEWHERE_SINCE_NOT_SURE

/**
 * @brief libprge core local player node class
 * 
 * @note user for game local player
 * @note should be only one node under "/root" node
 */
class CCoreLocalPlayerNode : public Node
{
    GDCLASS(CCoreLocalPlayerNode, Node);
private:
    /* data */

protected:
    static void _bind_methods();

public:
    CCoreLocalPlayerNode(/* args */);
    ~CCoreLocalPlayerNode();

    ui64 m_playerId; // public: player unsigned int id
    /**
     * @brief set player id
     * 
     * @param playerId 
     */
    void setPlayerId(ui64 playerId);
    /**
     * @brief get player id
     * 
     * @return ui64 
     */
    ui64 getPlayerId();

    //////////////////////////////////////////////////////

    String m_playerIdString; // public: player string id
    /**
     * @brief set player id string
     * 
     * @note mind to use uuid v4
     * @param playerIdString 
     */
    void   setPlayerIdString(String playerIdString);
    /**
     * @brief get player id string
     * 
     * @return String 
     */
    String getPlayerIdString();

    //////////////////////////////////////////////////////

    ECoreLocalPlayerNodeState m_stateType; // public: player state type
    /**
     * @brief set state type
     * 
     * @param stateType 
     */
    void                      setStateType(ECoreLocalPlayerNodeState stateType);
    /**
     * @brief get state type
     * 
     * @return ECoreLocalPlayerNodeState 
     */
    ECoreLocalPlayerNodeState getStateType();

    //////////////////////////////////////////////////////

    /**
     * @brief tell if this is CCoreLocalPlayerNode class
     * 
     * @return true 
     * @return false 
     */
    bool isCCoreLocalPlayerNode() { return true; }
};

// default class name for CCoreLocalPlayerNode
inline static const char *CCoreLocalPlayerNode_CLASS = "CCoreLocalPlayerNode";

// signal stateType changed for CCoreLocalPlayerNode
inline static const char *CCoreLocalPlayerNodeSignals_stateType_changed = "stateType_changed";

#endif // LIBPRGE_CORE_LOCAL_PLAYER_NODE_HH
