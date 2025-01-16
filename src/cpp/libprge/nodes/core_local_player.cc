#include "core_local_player.hh"

VARIANT_ENUM_CAST(ECoreLocalPlayerState);

#include <libprge/functions/utility_funcs.hh>

void CCoreLocalPlayer::_bind_methods()
{
    // player
    ADD_GROUP("Player", "m_player");
    {
        ClassDB::bind_method(D_METHOD("setPlayerId", "playerId"), &CCoreLocalPlayer::setPlayerId);
        ClassDB::bind_method(D_METHOD("getPlayerId"), &CCoreLocalPlayer::getPlayerId);
        ClassDB::add_property(CCoreLocalPlayer_CLASS, PropertyInfo(
            Variant::Type::INT, "m_playerId"
        ), "setPlayerId", "getPlayerId");

        ClassDB::bind_method(D_METHOD("setPlayerIdString", "playerIdString"), &CCoreLocalPlayer::setPlayerIdString);
        ClassDB::bind_method(D_METHOD("getPlayerIdString"), &CCoreLocalPlayer::getPlayerIdString);
        ClassDB::add_property(CCoreLocalPlayer_CLASS, PropertyInfo(
            Variant::Type::STRING, "m_playerIdString"
        ), "setPlayerIdString", "getPlayerIdString");
    }

    // state
    ADD_GROUP("State", "m_state");
    {
        String stateType;
        ClassDB::bind_method(D_METHOD("setStateType", "stateType"), &CCoreLocalPlayer::setStateType);
        ClassDB::bind_method(D_METHOD("getStateType"), &CCoreLocalPlayer::getStateType);
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_UNDEFINED);
                stateType += CORE_LOCAL_PLAYER_STATE_UNDEFINED_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_LOADING);
                stateType += CORE_LOCAL_PLAYER_STATE_LOADING_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_IN_MENU);
                stateType += CORE_LOCAL_PLAYER_STATE_IN_MENU_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_IN_GAMEPLAY);
                stateType += CORE_LOCAL_PLAYER_STATE_IN_GAMEPLAY_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_IN_GAMEPLAY_MENU);
                stateType += CORE_LOCAL_PLAYER_STATE_IN_GAMEPLAY_MENU_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_IN_GAMEPLAY_INTERACTION);
                stateType += CORE_LOCAL_PLAYER_STATE_IN_GAMEPLAY_INTERACTION_HINT;
                stateType += ",";
            BIND_ENUM_CONSTANT(CORE_LOCAL_PLAYER_STATE_IN_SOMEWHERE_SINCE_NOT_SURE);
                stateType += CORE_LOCAL_PLAYER_STATE_IN_SOMEWHERE_SINCE_NOT_SURE_HINT;
                stateType += "";
        ClassDB::add_property(CCoreLocalPlayer_CLASS, PropertyInfo(
            Variant::Type::INT, "m_stateType",
            PROPERTY_HINT_ENUM, stateType
        ), "setStateType", "getStateType");
    }

    // signals
    {
        ADD_SIGNAL(MethodInfo(CCoreLocalPlayerSignals_stateType_changed));
    }

    // extend functions
    {
        ClassDB::bind_method(D_METHOD("isCCoreLocalPlayer"), &CCoreLocalPlayer::isCCoreLocalPlayer);
    }
}

CCoreLocalPlayer::CCoreLocalPlayer()
{
    m_playerId = 0;

    m_playerIdString = utilityFunctions::generate::uuid(4).c_str();

    m_stateType = CORE_LOCAL_PLAYER_STATE_UNDEFINED;
}

CCoreLocalPlayer::~CCoreLocalPlayer()
{
}

void CCoreLocalPlayer::setPlayerId(ui64 playerId)
{
    if (playerId <= 0) { playerId = 0; }
    if (playerId >= UINT64_MAX ) { playerId = UINT64_MAX; }
    m_playerId = playerId;
}

ui64 CCoreLocalPlayer::getPlayerId()
{
    return m_playerId;
}

void CCoreLocalPlayer::setPlayerIdString(String playerIdString)
{
    m_playerIdString = playerIdString;
}

String CCoreLocalPlayer::getPlayerIdString()
{
    return m_playerIdString;
}

void CCoreLocalPlayer::setStateType(ECoreLocalPlayerState stateType)
{
    m_stateType = stateType;
    emit_signal(CCoreLocalPlayerSignals_stateType_changed);
}

ECoreLocalPlayerState CCoreLocalPlayer::getStateType()
{
    return m_stateType;
}
