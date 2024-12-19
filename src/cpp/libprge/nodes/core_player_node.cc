#include "core_player_node.hh"

namespace libprge
{

void CCorePlayerNode::_bind_methods()
{
    // virtual functions/methods
    // in-game
    {
        BIND_VIRTUAL_METHOD(CCorePlayerNode, onReadyInGameRT);
        BIND_VIRTUAL_METHOD(CCorePlayerNode, onInputInGameRT);
        BIND_VIRTUAL_METHOD(CCorePlayerNode, onProcessInGameRT);
        BIND_VIRTUAL_METHOD(CCorePlayerNode, onPhysicsProcessInGameRT);
    }
}

CCorePlayerNode::CCorePlayerNode()
{
    // lastly
    this->set_name(m_defaultName);
}

CCorePlayerNode::~CCorePlayerNode()
{
}

void CCorePlayerNode::_input(Ref<InputEvent> pEvent)
{
    if (!Engine::get_singleton()->is_editor_hint())
    {
        onInputInGameRT(pEvent);
    }
}

void CCorePlayerNode::onReadyInGameRT()
{
    /* NOT IMPLEMENTED */
}

void CCorePlayerNode::onInputInGameRT(const Ref<InputEvent> &pEvent)
{
    if (pEvent.is_null()) { return; }

    #pragma message("TODO: CCorePlayerNode::onInputInGameRT")
}

void CCorePlayerNode::onProcessInGameRT()
{
    /* NOT IMPLEMENTED */
}

void CCorePlayerNode::onPhysicsProcessInGameRT()
{
    /* NOT IMPLEMENTED */
}

} // namespace libprge
