#ifndef LIBPRGE_CORE_PLAYER_NODE_HH
#define LIBPRGE_CORE_PLAYER_NODE_HH
#include <libprge/base/config.hh>
#include <libprge/interfaces/iin_game_controller.hh>
#include <libprge/functions/logger_funcs.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>

namespace libprge
{

using namespace godot;

static const char *CCorePlayerNode_CLASS = "CCorePlayerNode";
static const char *CCorePlayerNode_BRIEF = R"(class CCorePlayerNode
* @brief libprge core player node class
)";

/**
 * @brief libprge core player node class
 * 
 * @note only act in-game mode, not in editor mode
 */
class CCorePlayerNode : public Node
                      , public IInGameController
{
    GDCLASS(CCorePlayerNode, Node);
private:
    const String m_defaultName = "core-player";

    i64 m_id = 0;

    // this could be uuid v1 or v3 depend on your implementation
    String m_uuid = "";

    // game data

protected:
    static void _bind_methods();

public:
    CCorePlayerNode(/* args */);
    ~CCorePlayerNode();

    void setId(i64 id) { m_id = id; }
    i64  getId() { return m_id; }

    void   setUuid(String uuid) { m_uuid = uuid; }
    String setUuid() { return m_uuid; }

    void _input(Ref<InputEvent> pEvent);

#pragma region required interface in-game implementation
    /* NOT IMPLEMENTED */
    void onReadyInGameRT();

    void onInputInGameRT(const Ref<InputEvent> &pEvent);

    /* NOT IMPLEMENTED */
    void onProcessInGameRT();

    /* NOT IMPLEMENTED */
    void onPhysicsProcessInGameRT();
#pragma endregion
};

} // namespace libprge

#endif // LIBPRGE_CORE_PLAYER_NODE_HH
