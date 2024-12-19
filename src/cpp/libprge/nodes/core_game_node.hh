#ifndef LIBPRGE_CORE_GAME_NODE_HH
#define LIBPRGE_CORE_GAME_NODE_HH
#include <libprge/base/config.hh>
#include <libprge/constants/string_const.hh>
#include <libprge/enums/distribution_enums.hh>
#include <libprge/functions/logger_funcs.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/core/binder_common.hpp>

namespace libprge
{

using namespace godot;

// replacement enum distribution os for CCoreGameNode
enum DISTRIBUTION_OS_ENUM : i32
{
    DISTRIBUTION_OS_UNDEFINED = EDistributionOS::ENUM::DISTRIBUTION_OS_UNDEFINED,
    DISTRIBUTION_OS_LINUX = EDistributionOS::ENUM::DISTRIBUTION_OS_LINUX,
    DISTRIBUTION_OS_WINDOWS = EDistributionOS::ENUM::DISTRIBUTION_OS_WINDOWS,
    DISTRIBUTION_OS_MACOS = EDistributionOS::ENUM::DISTRIBUTION_OS_MACOS,
};

// replacement code distribution os for CCoreGameNode
struct DISTRIBUTION_OS_CODE : public EDistributionOS::CODE
{
    // RESERVED
};

// replacement enum distribution store for CCoreGameNode
enum DISTRIBUTION_STORE_ENUM : i32
{
    DISTRIBUTION_STORE_UNDEFINED = EDistributionStore::ENUM::DISTRIBUTION_STORE_UNDEFINED,
    DISTRIBUTION_STORE_STEAM = EDistributionStore::ENUM::DISTRIBUTION_STORE_STEAM,
    DISTRIBUTION_STORE_GOG = EDistributionStore::ENUM::DISTRIBUTION_STORE_GOG,
    DISTRIBUTION_STORE_ITCHIO = EDistributionStore::ENUM::DISTRIBUTION_STORE_ITCHIO,
    DISTRIBUTION_STORE_MISC_OR_CUSTOM = EDistributionStore::ENUM::DISTRIBUTION_STORE_MISC_OR_CUSTOM,
};

// replacement code distribution store for CCoreGameNode
struct DISTRIBUTION_STORE_CODE : public EDistributionStore::CODE
{
    // RESERVED
};

static const char *CCoreGameNode_CLASS = "CCoreGameNode";
static const char *CCoreGameNode_BRIEF = R"(class CCoreGameNode
* @brief libprge core game node class
)";

/**
 * @brief libprge core game node class
 */
class CCoreGameNode : public Node
{
    GDCLASS(CCoreGameNode, Node);
private:
    const String m_defaultName = "core-game";

    String m_gameName = "";

    i32    m_versionMajor = 0;
    i32    m_versionMinor = 0;
    i32    m_versionPatch = 0;
    i32    m_versionDates = 20201230;
    String m_versionString = "";

    DISTRIBUTION_OS_ENUM m_distributionOSEnum = DISTRIBUTION_OS_ENUM::DISTRIBUTION_OS_UNDEFINED;
    String               m_distributionOSCode = "";

    DISTRIBUTION_STORE_ENUM m_distributionStoreEnum = DISTRIBUTION_STORE_ENUM::DISTRIBUTION_STORE_UNDEFINED;
    String                  m_distributionStoreCode = "";

    bool m_isDedicatedServer = false;

    String m_bindIp = "127.0.0.1";
    i32    m_bindPort = 10000;

protected:
    static void _bind_methods();

public:
    CCoreGameNode(/* args */);
    ~CCoreGameNode();

    void   setGameName(String gameName) { m_gameName = gameName; }
    String getGameName() { return m_gameName; }

    void setVersionMajor(i32 versionMajor) { m_versionMajor = versionMajor; }
    i32  getVersionMajor() { return m_versionMajor; }

    void setVersionMinor(i32 versionMinor) { m_versionMinor = versionMinor; }
    i32  getVersionMinor() { return m_versionMinor; }

    void setVersionPatch(i32 versionPatch) { m_versionPatch = versionPatch; }
    i32  getVersionPatch() { return m_versionPatch; }

    void setVersionDates(i32 versionDates) { m_versionDates = versionDates; }
    i32  getVersionDates() { return m_versionDates; }

    String getVersionString()
    {
        m_versionString = "";
        m_versionString += String::num(m_versionMajor);
            m_versionString += ".";
        m_versionString += String::num(m_versionMinor);
            m_versionString += ".";
        m_versionString += String::num(m_versionPatch);
            m_versionString += ".";
        m_versionString += String::num(m_versionDates);
        return m_versionString;
    }

    DISTRIBUTION_OS_ENUM getDistributionOSEnum()
    {
        auto pOS = OS::get_singleton();

        if (pOS->get_name() == STRINGS_OS_GODOT::LINUX)
        {
            return DISTRIBUTION_OS_LINUX;
        }

        if (pOS->get_name() == STRINGS_OS_GODOT::WINDOWS)
        {
            return DISTRIBUTION_OS_WINDOWS;
        }

        if (pOS->get_name() == STRINGS_OS_GODOT::MACOS)
        {
            return DISTRIBUTION_OS_MACOS;
        }

        return DISTRIBUTION_OS_UNDEFINED;
    }

    String getDistributionOSString() { return m_distributionOSCode; }

    void                    setDistributionStoreEnum(DISTRIBUTION_STORE_ENUM distributionStoreNameEnum) { m_distributionStoreEnum = distributionStoreNameEnum; }
    DISTRIBUTION_STORE_ENUM getDistributionStoreEnum() { return m_distributionStoreEnum; }

    void   setDistributionStoreString(String distributionStoreNameString) { m_distributionStoreCode = distributionStoreNameString; }
    String getDistributionStoreString() { return m_distributionStoreCode; }

    void setIsDedicatedServer(bool trueOrFalse) { m_isDedicatedServer = trueOrFalse; }
    bool getIsDedicatedServer() { return m_isDedicatedServer; }

    void   setBindIp(String ipAddress) { m_bindIp = ipAddress; }
    String getBindIp() { return m_bindIp; }

    void setBindPort(i32 portNumber) { m_bindPort = portNumber; }
    i32  getBindPort() { return m_bindPort; }
};

} // namespace libprge

#endif // LIBPRGE_CORE_GAME_NODE_HH
