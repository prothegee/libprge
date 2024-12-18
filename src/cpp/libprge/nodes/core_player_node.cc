#include "core_player_node.hh"

namespace libprge
{

void CCorePlayerNode::_bind_methods()
{
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

    logger::log::debug("TODO: CCorePlayer onInputInGameRT");
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
