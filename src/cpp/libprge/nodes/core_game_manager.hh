#ifndef LIBPRGE_CORE_GAME_MANAGER_HH
#define LIBPRGE_CORE_GAME_MANAGER_HH
#include <libprge/libprge.hh>

#include <godot_cpp/classes/node.hpp>

/**
 * @brief game distribution target
 */
enum EGameDistributionTarget : i32
{
    GAME_DISTRIBUTION_TARGET_UNDEFINED,
    GAME_DISTRIBUTION_TARGET_DESKTOP,
    GAME_DISTRIBUTION_TARGET_MOBILE,
    GAME_DISTRIBUTION_TARGET_CONSOLE,
    GAME_DISTRIBUTION_TARGET_WEB,
};
inline static cchar *GAME_DISTRIBUTION_TARGET_UNDEFINED_HINT = "Undefined"; // hint for GAME_DISTRIBUTION_TARGET_UNDEFINED
inline static cchar *GAME_DISTRIBUTION_TARGET_DESKTOP_HINT = "Desktop"; // hint for GAME_DISTRIBUTION_TARGET_DESKTOP
inline static cchar *GAME_DISTRIBUTION_TARGET_MOBILE_HINT = "Mobile"; // hint for GAME_DISTRIBUTION_TARGET_MOBILE
inline static cchar *GAME_DISTRIBUTION_TARGET_CONSOLE_HINT = "Console"; // hint for GAME_DISTRIBUTION_TARGET_CONSOLE
inline static cchar *GAME_DISTRIBUTION_TARGET_WEB_HINT = "Web"; // hint for GAME_DISTRIBUTION_TARGET_WEB

/**
 * @brief libprge core game manager node class
 * 
 * @note use for managing game project externally
 * @note there should be only one node under "/root" node
 */
class CCoreGameManager : public Node
{
    GDCLASS(CCoreGameManager, Node);
private:
    String m_gameLongName; // private: game long name

    String m_gameShortName; // private: game short name

    i32    m_versionMajor; // private: version major
    i32    m_versionMinor; // private: version minor
    i32    m_versionPatch; // private: version patch
    i32    m_versionDates; // private: version dates

    EGameDistributionTarget m_distributionTarget; // private: distribution target e.g. Desktop, Mobile, & etc.
    String                  m_distributionStore; // private: distribution store, e.g. Steam, itch.io, GoG, or custom

protected:
    static void _bind_methods();

public:
    CCoreGameManager(/* args */);
    ~CCoreGameManager();

    //////////////////////////////////////////////////////

    /**
     * @brief set game long name
     * 
     * @param gameLongName 
     */
    void   setGameLongName(String gameLongName);
    /**
     * @brief get game long name
     * 
     * @return String 
     */
    String getGameLongName();

    //////////////////////////////////////////////////////

    /**
     * @brief set game short name
     * 
     * @param gameShortName 
     */
    void   setGameShortName(String gameShortName);
    /**
     * @brief get game short name
     * 
     * @return String 
     */
    String getGameShortName();

    //////////////////////////////////////////////////////

    /**
     * @brief set version major
     * 
     * @param versionMajor 
     */
    void setVersionMajor(i32 versionMajor);
    /**
     * @brief get version major
     * 
     * @return i32 
     */
    i32  getVersionMajor();

    //////////////////////////////////////////////////////

    /**
     * @brief set version minor
     * 
     * @param versionMinor 
     */
    void setVersionMinor(i32 versionMinor);
    /**
     * @brief get version minor
     * 
     * @return i32 
     */
    i32  getVersionMinor();

    //////////////////////////////////////////////////////

    /**
     * @brief set version patch
     * 
     * @param versionPatch 
     */
    void setVersionPatch(i32 versionPatch);
    /**
     * @brief get version patch
     * 
     * @return i32 
     */
    i32  getVersionPatch();

    //////////////////////////////////////////////////////

    /**
     * @brief set version dates
     * 
     * @param versionDates 
     */
    void setVersionDates(i32 versionDates);
    /**
     * @brief get version dates
     * 
     * @return i32 
     */
    i32  getVersionDates();

    //////////////////////////////////////////////////////

    /**
     * @brief get version full string i.e. MAJOR.MINOR.PATCH.YYYYMMDD
     * 
     * @return String 
     */
    String getVersionFullString();

    //////////////////////////////////////////////////////

    /**
     * @brief set distribution target
     * 
     * @param distributionTarget 
     */
    void                    setDistributionTarget(EGameDistributionTarget distributionTarget);
    /**
     * @brief get distribution target
     * 
     * @return EGameDistributionTarget 
     */
    EGameDistributionTarget getDistributionTarget();

    //////////////////////////////////////////////////////

    /**
     * @brief set distribution store
     * 
     * @param distributionStore 
     */
    void   setDistributionStore(String distributionStore);
    /**
     * @brief get distribution store
     * 
     * @return String 
     */
    String getDistributionStore();

    //////////////////////////////////////////////////////

    /**
     * @brief get distribution system, i.e. Windows, Linux Debian, etc.
     * 
     * @return String 
     */
    String getDistributionSystem();

    //////////////////////////////////////////////////////

    /**
     * @brief tell if this is CCoreGameManager class
     * 
     * @return true 
     * @return false 
     */
    bool isCCoreGameManager() { return true; }
};

// default class name for CCoreGameManager
inline static cchar *CCoreGameManager_CLASS = "CCoreGameManager";

#endif // LIBPRGE_CORE_GAME_MANAGER_HH
