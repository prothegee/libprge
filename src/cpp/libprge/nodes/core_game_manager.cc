#include "core_game_manager.hh"

VARIANT_ENUM_CAST(EGameDistributionTarget);

void CCoreGameManager::_bind_methods()
{
    // game
    ADD_GROUP("Game", "m_game");
    {
        ClassDB::bind_method(D_METHOD("setGameLongName", "gameLongName"), &CCoreGameManager::setGameLongName);
        ClassDB::bind_method(D_METHOD("getGameLongName"), &CCoreGameManager::getGameLongName);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::STRING, "m_gameLongName"
        ), "setGameLongName", "getGameLongName");

        ClassDB::bind_method(D_METHOD("setGameShortName", "gameShortName"), &CCoreGameManager::setGameShortName);
        ClassDB::bind_method(D_METHOD("getGameShortName"), &CCoreGameManager::getGameShortName);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::STRING, "m_gameShortName"
        ), "setGameShortName", "getGameShortName");
    }

    // version
    ADD_GROUP("Version", "m_version");
    {
        ClassDB::bind_method(D_METHOD("setVersionMajor", "versionMajor"), &CCoreGameManager::setVersionMajor);
        ClassDB::bind_method(D_METHOD("getVersionMajor"), &CCoreGameManager::getVersionMajor);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::INT, "m_versionMajor"
        ), "setVersionMajor", "getVersionMajor");

        ClassDB::bind_method(D_METHOD("setVersionMinor", "versionMinor"), &CCoreGameManager::setVersionMinor);
        ClassDB::bind_method(D_METHOD("getVersionMinor"), &CCoreGameManager::getVersionMinor);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::INT, "m_versionMinor"
        ), "setVersionMinor", "getVersionMinor");

        ClassDB::bind_method(D_METHOD("setVersionPatch", "versionPatch"), &CCoreGameManager::setVersionPatch);
        ClassDB::bind_method(D_METHOD("getVersionPatch"), &CCoreGameManager::getVersionPatch);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::INT, "m_versionPatch"
        ), "setVersionPatch", "getVersionPatch");

        ClassDB::bind_method(D_METHOD("setVersionDates", "versionDates"), &CCoreGameManager::setVersionDates);
        ClassDB::bind_method(D_METHOD("getVersionDates"), &CCoreGameManager::getVersionDates);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::INT, "m_versionDates"
        ), "setVersionDates", "getVersionDates");
        ClassDB::bind_method(D_METHOD("getVersionFullString"), &CCoreGameManager::getVersionFullString);
    }

    // distribution
    ADD_GROUP("Distribution", "m_distribution");
    {
        String distributionTarget;
        ClassDB::bind_method(D_METHOD("setDistributionTarget", "distributionTarget"), &CCoreGameManager::setDistributionTarget);
        ClassDB::bind_method(D_METHOD("getDistributionTarget"), &CCoreGameManager::getDistributionTarget);
            BIND_ENUM_CONSTANT(GAME_DISTRIBUTION_TARGET_UNDEFINED);
                distributionTarget += GAME_DISTRIBUTION_TARGET_UNDEFINED_HINT;
                distributionTarget += ",";
            BIND_ENUM_CONSTANT(GAME_DISTRIBUTION_TARGET_DESKTOP);
                distributionTarget += GAME_DISTRIBUTION_TARGET_DESKTOP_HINT;
                distributionTarget += ",";
            BIND_ENUM_CONSTANT(GAME_DISTRIBUTION_TARGET_MOBILE);
                distributionTarget += GAME_DISTRIBUTION_TARGET_MOBILE_HINT;
                distributionTarget += ",";
            BIND_ENUM_CONSTANT(GAME_DISTRIBUTION_TARGET_CONSOLE);
                distributionTarget += GAME_DISTRIBUTION_TARGET_CONSOLE_HINT;
                distributionTarget += ",";
            BIND_ENUM_CONSTANT(GAME_DISTRIBUTION_TARGET_WEB);
                distributionTarget += GAME_DISTRIBUTION_TARGET_WEB_HINT;
                distributionTarget += "";
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::INT, "m_distributionTarget",
            PROPERTY_HINT_ENUM, distributionTarget
        ), "setDistributionTarget", "getDistributionTarget");

        ClassDB::bind_method(D_METHOD("setDistributionStore", "distributionStore"), &CCoreGameManager::setDistributionStore);
        ClassDB::bind_method(D_METHOD("getDistributionStore"), &CCoreGameManager::getDistributionStore);
        ClassDB::add_property(CCoreGameManager_CLASS, PropertyInfo(
            Variant::Type::STRING, "m_distributionStore"
        ), "setDistributionStore", "getDistributionStore");
        
        ClassDB::bind_method(D_METHOD("getDistributionSystem"), &CCoreGameManager::getDistributionSystem);
    }

    // none editor property
    {
    }

    // signals
    {
    }

    // extend functions
    {
        ClassDB::bind_method(D_METHOD("isCCoreGameManager"), &CCoreGameManager::isCCoreGameManager);
    }
}

CCoreGameManager::CCoreGameManager()
{
    m_gameLongName = "Game Long Name";
    m_gameShortName = "Game Short Name";

    m_versionMajor = 0;
    m_versionMinor = 0;
    m_versionPatch = 0;
    m_versionDates = 30301230;

    m_distributionTarget = GAME_DISTRIBUTION_TARGET_UNDEFINED;

    m_distributionStore = "Steam/itch.io/GoG/etc.";
}

CCoreGameManager::~CCoreGameManager()
{
}

void CCoreGameManager::setGameLongName(String gameLongName)
{
    m_gameLongName = gameLongName;
}

String CCoreGameManager::getGameLongName()
{
    return m_gameLongName;
}

void CCoreGameManager::setGameShortName(String gameShortName)
{
    m_gameShortName = gameShortName;
}

String CCoreGameManager::getGameShortName()
{
    return m_gameShortName;
}

void CCoreGameManager::setVersionMajor(i32 versionMajor)
{
    m_versionMajor = versionMajor;
}

i32 CCoreGameManager::getVersionMajor()
{
    return m_versionMajor;
}

void CCoreGameManager::setVersionMinor(i32 versionMinor)
{
    m_versionMinor = versionMinor;
}

i32 CCoreGameManager::getVersionMinor()
{
    return m_versionMinor;
}

void CCoreGameManager::setVersionPatch(i32 versionPatch)
{
    m_versionPatch = versionPatch;
}

i32 CCoreGameManager::getVersionPatch()
{
    return m_versionPatch;
}

void CCoreGameManager::setVersionDates(i32 versionDates)
{
    m_versionDates = versionDates;
}

i32 CCoreGameManager::getVersionDates()
{
    return m_versionDates;
}

String CCoreGameManager::getVersionFullString()
{
    return String(String::num_int64(m_versionMajor) + "." + String::num_int64(m_versionMinor) + "." + String::num_int64(m_versionPatch) + "." + String::num_int64(m_versionDates));
}

void CCoreGameManager::setDistributionTarget(EGameDistributionTarget distributionTarget)
{
    m_distributionTarget = distributionTarget;
}

EGameDistributionTarget CCoreGameManager::getDistributionTarget()
{
    return m_distributionTarget;
}

void CCoreGameManager::setDistributionStore(String distributionStore)
{
    m_distributionStore = distributionStore;
}

String CCoreGameManager::getDistributionStore()
{
    return m_distributionStore;
}

String CCoreGameManager::getDistributionSystem()
{
    String result;

    auto pOS = OS::get_singleton();

    if (pOS->get_name() != pOS->get_distribution_name())
    {
        result += pOS->get_name();
        result += " ";
        result += pOS->get_distribution_name();
    }
    else
    {
        result += pOS->get_name();
    }

    return result;
}
