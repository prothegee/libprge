#ifndef LIBPRGE_CORE_NETWORK_NODE_HH
#define LIBPRGE_CORE_NETWORK_NODE_HH
#include <libprge/base/config.hh>
#include <libprge/enums/result_enums.hh>
#include <libprge/functions/logger_funcs.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/http_client.hpp>
#include <godot_cpp/classes/http_request.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/core/binder_common.hpp>

namespace libprge
{

using namespace godot;

// network result for CCoreNetworkNode
enum NETWORK_RESULT : i32
{
    NETWORK_RESULT_UNDEFINED = EResult::ENUM::RESULT_UNDEFINED,
    NETWORK_RESULT_OK = EResult::ENUM::RESULT_OK,
    NETWORK_RESULT_ERROR = EResult::ENUM::RESULT_EXISTS,
    NETWORK_RESULT_DOESNT_EXISTS = EResult::ENUM::RESULT_DOESNT_EXISTS,
    NETWORK_RESULT_FOUND = EResult::ENUM::RESULT_FOUND,
    NETWORK_RESULT_NOT_FOUND = EResult::ENUM::RESULT_NOT_FOUND,
    NETWORK_RESULT_SIZE_IS_OK = EResult::ENUM::RESULT_SIZE_IS_OK,
    NETWORK_RESULT_SIZE_IS_EMPTY = EResult::ENUM::RESULT_SIZE_IS_EMPTY,
    NETWORK_RESULT_RESPONSE_IS_OK = EResult::ENUM::RESULT_RESPONSE_IS_OK,
    NETWORK_RESULT_RESPONSE_IS_FAIL = EResult::ENUM::RESULT_RESPONSE_IS_FAIL,
    NETWORK_RESULT_REQUEST_OK = EResult::ENUM::RESULT_REQUEST_OK,
    NETWORK_RESULT_REQUEST_ERROR_OR_FAIL = EResult::ENUM::RESULT_REQUEST_ERROR_OR_FAIL,
    NETWORK_RESULT_CONNECTION_OK = EResult::ENUM::RESULT_CONNECTION_OK,
    NETWORK_RESULT_CONNECTION_FAIL = EResult::ENUM::RESULT_CONNECTION_FAIL,
    NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK = EResult::ENUM::RESULT_CONNECTING_AND_RESOLVING_OK,
    NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL = EResult::ENUM::RESULT_CONNECTING_AND_RESOLVING_FAIL,
    NETWORK_RESULT_PRODUCT_REGISTRATION_OK = EResult::ENUM::RESULT_PRODUCT_REGISTRATION_OK,
    NETWORK_RESULT_PRODUCT_REGISTRATION_ERROR = EResult::ENUM::RESULT_PRODUCT_REGISTRATION_ERROR,
    NETWORK_RESULT_PRODUCT_CHECKING_OK = EResult::ENUM::RESULT_PRODUCT_CHECKING_OK,
    NETWORK_RESULT_PRODUCT_CHECKING_ERROR = EResult::ENUM::RESULT_PRODUCT_CHECKING_ERROR,
    NETWORK_RESULT_PRODUCT_ORIGINALITY_OK = EResult::ENUM::RESULT_PRODUCT_ORIGINALITY_OK,
    NETWORK_RESULT_PRODUCT_ORIGINALITY_ERROR = EResult::ENUM::RESULT_PRODUCT_ORIGINALITY_ERROR,
};

static const char *CCoreNetworkNode_CLASS = "CCoreNetworkNode";
static const char *CCoreNetworkNode_BRIEF = R"(class CCoreNetworkNode final
* @brief libprge core network node class
)";

/**
 * @brief libprge core network node class
 */
class CCoreNetworkNode : public Node
{
    GDCLASS(CCoreNetworkNode, Node);
private:
    const String m_defaultName = "core-network";

protected:
    static void _bind_methods();

public:
    CCoreNetworkNode(/* args */);
    ~CCoreNetworkNode();

    /**
     * @brief make http request
     * 
     * @note !POSTPONE
     * 
     * @param url e.g. http://domain.tld ( do not include endpoint as slash, i.e. http://domain.tld/ )
     * @param endpoint e.g. /v1/sign-in
     * @param method 
     * @param headers 
     * @param byteData byte data to pass
     * @param stringData string response result to pass
     * @param delay delay when make poll
     * @return NETWORK_RESULT
     */
    NETWORK_RESULT makeHttpRequest(String url, String endpoint, HTTPClient::Method method, PackedStringArray headers, PackedByteArray byteData, String stringData, const i32 delay = 300);
    // NETWORK_RESULT makeHttpRequest(const String &url, const String &endpoint, const HTTPClient::Method &method, const PackedStringArray &headers, PackedByteArray &byteData, String &stringData, const int32_t &delay = 300);
};

} // namespace libprge

#endif // LIBPRGE_CORE_NETWORK_NODE_HH
