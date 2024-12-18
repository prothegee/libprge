#ifndef LIBPRGE_CORE_PLAYER_NODE_HH
#define LIBPRGE_CORE_PLAYER_NODE_HH
#include <libprge/base/config.hh>
#include <libprge/interfaces/iin_game_controller.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>

namespace libprge
{

using namespace godot;

static const char *CCorePlayerNode_CLASS = "CCorePlayerNode";
static const char *CCorePlayerNode_BRIEF = R"(class CCorePlayerNode final
* @brief libprge core player node class
)";

/**
 * @brief libprge core player node class
 */

class CCorePlayerNode : public Node
{
    GDCLASS(CCorePlayerNode, Node);
private:
    /* data */

protected:
    static void _bind_methods();

public:
    CCorePlayerNode(/* args */);
    ~CCorePlayerNode();
};

} // namespace libprge

#endif // LIBPRGE_CORE_PLAYER_NODE_HH
