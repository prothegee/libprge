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
        ADD_SUBGROUP("Version", "info_version_");
    // versions
    {
        // major
        ClassDB::bind_method(D_METHOD("setVersionMajor", "versionMajor"), &CCoreGameNode::setVersionMajor);
        ClassDB::bind_method(D_METHOD("getVersionMajor"), &CCoreGameNode::getVersionMajor);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::INT, "info_version_major"
        ), "setVersionMajor", "getVersionMajor");

        // minor
        ClassDB::bind_method(D_METHOD("setVersionMinor", "versionMinor"), &CCoreGameNode::setVersionMinor);
        ClassDB::bind_method(D_METHOD("getVersionMinor"), &CCoreGameNode::getVersionMinor);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::INT, "info_version_minor"
        ), "setVersionMinor", "getVersionMinor");

        // patch
        ClassDB::bind_method(D_METHOD("setVersionPatch", "versionPatch"), &CCoreGameNode::setVersionPatch);
        ClassDB::bind_method(D_METHOD("getVersionPatch"), &CCoreGameNode::getVersionPatch);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::INT, "info_version_patch"
        ), "setVersionPatch", "getVersionPatch");

        // dates
        ClassDB::bind_method(D_METHOD("setVersionDates", "versionDates"), &CCoreGameNode::setVersionDates);
        ClassDB::bind_method(D_METHOD("getVersionDates"), &CCoreGameNode::getVersionDates);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::INT, "info_version_dates"
        ), "setVersionDates", "getVersionDates");

        // string
        ClassDB::bind_method(D_METHOD("getVersionString"), &CCoreGameNode::getVersionString);
    }
}

CCoreGameNode::CCoreGameNode()
{
}

CCoreGameNode::~CCoreGameNode()
{
}

} // namespace libprge
