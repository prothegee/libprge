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
};

} // namespace libprge

#endif // LIBPRGE_CORE_GAME_NODE_HH
