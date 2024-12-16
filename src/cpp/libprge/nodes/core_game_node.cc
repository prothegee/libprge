#include "core_game_node.hh"

namespace libprge
{

void CCoreGameNode::_bind_methods()
{
    ADD_GROUP("Info", "info_");
    // game name
    {
        ClassDB::bind_method(D_METHOD("setGameName", "gameName"), &CCoreGameNode::setGameName);
        ClassDB::bind_method(D_METHOD("getGameName"), &CCoreGameNode::getGameName);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::STRING, "info_gameName"
        ), "setGameName", "getGameName");
    }
}

CCoreGameNode::CCoreGameNode()
{
}

CCoreGameNode::~CCoreGameNode()
{
}

} // namespace libprge
