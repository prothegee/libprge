#ifndef LIBPRGE_CORE_GAME_NODE_HH
#define LIBPRGE_CORE_GAME_NODE_HH
#include <libprge/base/config.hh>
#include <libprge/functions/logger_funcs.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>

namespace libprge
{

using namespace godot;

static const char *CCoreGameNode_CLASS = "CCoreGameNode";
static const char *CCoreGameNode_BRIEF = R"(class CCoreGameNode final
* @brief libprge core game node class
)";

/**
 * @brief libprge core game node class
 */
class CCoreGameNode : public Node
{
    GDCLASS(CCoreGameNode, Node);
private:
    String m_gameName = "";

    i32    m_versionMajor = 0;
    i32    m_versionMinor = 0;
    i32    m_versionPatch = 0;
    i32    m_versionDates = 20201230;
    String m_versionString = "";

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

    String getVersionString() { return m_versionString; }
};

} // namespace libprge

#endif // LIBPRGE_CORE_GAME_NODE_HH
