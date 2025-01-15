#include "core_local_player_node.hh"

VARIANT_ENUM_CAST(ECoreLocalPlayerNodeState);

#include <libprge/functions/utility_funcs.hh>

void CCoreLocalPlayerNode::_bind_methods()
{
    // player
    ADD_GROUP("Player", "m_player");
    {
        ClassDB::bind_method(D_METHOD("setPlayerId", "playerId"), &CCoreLocalPlayerNode::setPlayerId);
        ClassDB::bind_method(D_METHOD("getPlayerId"), &CCoreLocalPlayerNode::getPlayerId);
        ClassDB::add_property(CCoreLocalPlayerNode_CLASS, PropertyInfo(
            Variant::Type::INT, "m_playerId"
        ), "setPlayerId", "getPlayerId");

        ClassDB::bind_method(D_METHOD("setPlayerIdString", "playerIdString"), &CCoreLocalPlayerNode::setPlayerIdString);
        ClassDB::bind_method(D_METHOD("getPlayerIdString"), &CCoreLocalPlayerNode::getPlayerIdString);
        ClassDB::add_property(CCoreLocalPlayerNode_CLASS, PropertyInfo(
            Variant::Type::STRING, "m_playerIdString"
        ), "setPlayerIdString", "getPlayerIdString");
    }

    // state
    ADD_GROUP("State", "m_state");
    {
        String stateType;
        ClassDB::bind_method(D_METHOD("setStateType", "stateType"), &CCoreLocalPlayerNode::setStateType);
        ClassDB::bind_method(D_METHOD("getStateType"), &CCoreLocalPlayerNode::getStateType);
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_NODE_STATE_UNDEFINED);
                stateType += CORE_LOCAL_PLAYER_NODE_STATE_UNDEFINED_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_NODE_STATE_LOADING);
                stateType += CORE_LOCAL_PLAYER_NODE_STATE_LOADING_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_NODE_STATE_IN_MENU);
                stateType += CORE_LOCAL_PLAYER_NODE_STATE_IN_MENU_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY);
                stateType += CORE_LOCAL_PLAYER_NODE_STATE_IN_GAMEPLAY_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_NODE_STATE_IN_SOMEWHERE_SINCE_NOT_SURE);
                stateType += CORE_LOCAL_PLAYER_NODE_STATE_IN_SOMEWHERE_SINCE_NOT_SURE_HINT;
                stateType += "";
        ClassDB::add_property(CCoreLocalPlayerNode_CLASS, PropertyInfo(
            Variant::Type::INT, "m_stateType",
            PROPERTY_HINT_ENUM, stateType
        ), "setStateType", "getStateType");
    }

    // signals
    {
        ADD_SIGNAL(MethodInfo(CCoreLocalPlayerNodeSignals_stateType_changed));
    }

    // extend functions
    {
        ClassDB::bind_method(D_METHOD("isCCoreLocalPlayerNode"), &CCoreLocalPlayerNode::isCCoreLocalPlayerNode);
    }
}

CCoreLocalPlayerNode::CCoreLocalPlayerNode()
{
    m_playerId = 0;

    m_playerIdString = utilityFunctions::generate::uuid(4).c_str();

    m_stateType = CORE_LOCAL_PLAYER_NODE_STATE_UNDEFINED;
}

CCoreLocalPlayerNode::~CCoreLocalPlayerNode()
{
}

void CCoreLocalPlayerNode::setPlayerId(ui64 playerId)
{
    if (playerId <= 0) { playerId = 0; }
    if (playerId >= UINT64_MAX ) { playerId = UINT64_MAX; }
    m_playerId = playerId;
}

ui64 CCoreLocalPlayerNode::getPlayerId()
{
    return m_playerId;
}

void CCoreLocalPlayerNode::setPlayerIdString(String playerIdString)
{
    m_playerIdString = playerIdString;
}

String CCoreLocalPlayerNode::getPlayerIdString()
{
    return m_playerIdString;
}

void CCoreLocalPlayerNode::setStateType(ECoreLocalPlayerNodeState stateType)
{
    m_stateType = stateType;
    emit_signal(CCoreLocalPlayerNodeSignals_stateType_changed);
}

ECoreLocalPlayerNodeState CCoreLocalPlayerNode::getStateType()
{
    return m_stateType;
}
