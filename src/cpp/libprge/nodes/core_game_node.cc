#include "core_game_node.hh"

VARIANT_ENUM_CAST(libprge::DISTRIBUTION_OS_ENUM);
VARIANT_ENUM_CAST(libprge::DISTRIBUTION_STORE_ENUM);

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

    ADD_GROUP("Distribution", "distribution_");
        ADD_SUBGROUP("Store", "distribution_store_");
    // distribution
    {
        // os enum
        ClassDB::bind_method(D_METHOD("getDistributionOSEnum"), &CCoreGameNode::getDistributionOSEnum);

        // os string
        ClassDB::bind_method(D_METHOD("getDistributionOSString"), &CCoreGameNode::getDistributionOSString);

        // store enum
        String distributionStore;

        BIND_ENUM_CONSTANT(DISTRIBUTION_STORE_ENUM::DISTRIBUTION_STORE_UNDEFINED);
        distributionStore += DISTRIBUTION_STORE_CODE::DISTRIBUTION_STORE_UNDEFINED;
            distributionStore += ",";

        BIND_ENUM_CONSTANT(DISTRIBUTION_STORE_ENUM::DISTRIBUTION_STORE_STEAM);
        distributionStore += DISTRIBUTION_STORE_CODE::DISTRIBUTION_STORE_STEAM;
            distributionStore += ",";

        BIND_ENUM_CONSTANT(DISTRIBUTION_STORE_ENUM::DISTRIBUTION_STORE_GOG);
        distributionStore += DISTRIBUTION_STORE_CODE::DISTRIBUTION_STORE_GOG;
            distributionStore += ",";

        BIND_ENUM_CONSTANT(DISTRIBUTION_STORE_ENUM::DISTRIBUTION_STORE_ITCHIO);
        distributionStore += DISTRIBUTION_STORE_CODE::DISTRIBUTION_STORE_ITCHIO;
            distributionStore += ",";

        BIND_ENUM_CONSTANT(DISTRIBUTION_STORE_ENUM::DISTRIBUTION_STORE_MISC_OR_CUSTOM);
        distributionStore += DISTRIBUTION_STORE_CODE::DISTRIBUTION_STORE_MISC_OR_CUSTOM;
            distributionStore += "";

        ClassDB::bind_method(D_METHOD("setDistributionStoreEnum", "distributionStoreEnum"), &CCoreGameNode::setDistributionStoreEnum);
        ClassDB::bind_method(D_METHOD("getDistributionStoreEnum"), &CCoreGameNode::getDistributionStoreEnum);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::INT, "distribution_store_enum",
            PropertyHint::PROPERTY_HINT_ENUM, distributionStore
        ), "setDistributionStoreEnum", "getDistributionStoreEnum");

        // store string
        ClassDB::bind_method(D_METHOD("setDistributionStoreString", "distributionStoreEnum"), &CCoreGameNode::setDistributionStoreString);
        ClassDB::bind_method(D_METHOD("getDistributionStoreString"), &CCoreGameNode::getDistributionStoreString);
        ClassDB::add_property(CCoreGameNode_CLASS, PropertyInfo(
            Variant::Type::STRING, "distribution_store_string"
        ), "setDistributionStoreString", "getDistributionStoreString");
    }
}

CCoreGameNode::CCoreGameNode()
{
    auto pOS = OS::get_singleton();

    auto OSname = pOS->get_name();
    auto OSdistribution = pOS->get_distribution_name();

    if (OSname == OSdistribution)
    {
        m_distributionOSCode = OSname;
    }
    else
    {
        m_distributionOSCode += OSname;
        m_distributionOSCode += " ";
        m_distributionOSCode += OSdistribution;
    }
}

CCoreGameNode::~CCoreGameNode()
{
}

} // namespace libprge
