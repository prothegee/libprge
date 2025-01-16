#ifndef LIBPRGE_CORE_NETWORK_MANAGER_HH
#define LIBPRGE_CORE_NETWORK_MANAGER_HH
#include <libprge/libprge.hh>

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/http_client.hpp>
#include <godot_cpp/classes/http_request.hpp>

/**
 * @brief network result enum
 */
enum ENetworkResult : i32
{
    NETWORK_RESULT_UNDEFINED,
    NETWORK_RESULT_OK,
    NETWORK_RESULT_ERROR,
    NETWORK_RESULT_DOESNT_EXISTS,
    NETWORK_RESULT_FOUND,
    NETWORK_RESULT_NOT_FOUND,
    NETWORK_RESULT_SIZE_IS_OK,
    NETWORK_RESULT_SIZE_IS_EMPTY,
    NETWORK_RESULT_RESPONSE_IS_OK,
    NETWORK_RESULT_RESPONSE_IS_FAIL,
    NETWORK_RESULT_REQUEST_OK,
    NETWORK_RESULT_REQUEST_ERROR_OR_FAIL,
    NETWORK_RESULT_CONNECTION_OK,
    NETWORK_RESULT_CONNECTION_FAIL,
    NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK,
    NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL,
};
inline static cchar *NETWORK_RESULT_UNDEFINED_HINT = "Undefined"; // hint for NETWORK_RESULT_UNDEFINED
inline static cchar *NETWORK_RESULT_OK_HINT = "Ok"; // hint for NETWORK_RESULT_OK
inline static cchar *NETWORK_RESULT_ERROR_HINT = "Error"; // hint for NETWORK_RESULT_ERROR
inline static cchar *NETWORK_RESULT_DOESNT_EXISTS_HINT = "Doesn't Exists"; // hint for NETWORK_RESULT_DOESNT_EXISTS
inline static cchar *NETWORK_RESULT_FOUND_HINT = "Found"; // hint for NETWORK_RESULT_FOUND
inline static cchar *NETWORK_RESULT_NOT_FOUND_HINT = "Not Found"; // hint for NETWORK_RESULT_NOT_FOUND
inline static cchar *NETWORK_RESULT_SIZE_IS_OK_HINT = "Size is Ok"; // hint for NETWORK_RESULT_SIZE_IS_OK
inline static cchar *NETWORK_RESULT_SIZE_IS_EMPTY_HINT = "Size is Empty"; // hint for NETWORK_RESULT_SIZE_IS_EMPTY
inline static cchar *NETWORK_RESULT_RESPONSE_IS_OK_HINT = "Response is Ok"; // hint for NETWORK_RESULT_RESPONSE_IS_OK
inline static cchar *NETWORK_RESULT_RESPONSE_IS_FAIL_HINT = "Response is Fail"; // hint for NETWORK_RESULT_RESPONSE_IS_FAIL
inline static cchar *NETWORK_RESULT_REQUEST_OK_HINT = "Request Ok"; // hint for NETWORK_RESULT_REQUEST_OK
inline static cchar *NETWORK_RESULT_REQUEST_ERROR_OR_FAIL_HINT = "Request Error/Fail"; // hint for NETWORK_RESULT_REQUEST_ERROR_OR_FAIL
inline static cchar *NETWORK_RESULT_CONNECTION_OK_HINT = "Connection Ok"; // hint for NETWORK_RESULT_CONNECTION_OK
inline static cchar *NETWORK_RESULT_CONNECTION_FAIL_HINT = "Connection Fail"; // hint for NETWORK_RESULT_CONNECTION_FAIL
inline static cchar *NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK_HINT = "Connecting & Resolving Ok"; // hint for NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK
inline static cchar *NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL_HINT = "Connecting & Resolving Fail"; // hint for NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL
/**
 * @brief convert network result as string from networkResultEnum param
 * 
 * @param networkResultEnum 
 * @return cchar* 
 */
inline static cchar *ENetworkResultAsString(const ENetworkResult networkResultEnum)
{
    switch (networkResultEnum)
    {
        case NETWORK_RESULT_UNDEFINED: { return NETWORK_RESULT_UNDEFINED_HINT; } break;
        case NETWORK_RESULT_OK: { return NETWORK_RESULT_OK_HINT; } break;
        case NETWORK_RESULT_ERROR: { return NETWORK_RESULT_ERROR_HINT; } break;
        case NETWORK_RESULT_DOESNT_EXISTS: { return NETWORK_RESULT_DOESNT_EXISTS_HINT; } break;
        case NETWORK_RESULT_FOUND: { return NETWORK_RESULT_FOUND_HINT; } break;
        case NETWORK_RESULT_NOT_FOUND: { return NETWORK_RESULT_NOT_FOUND_HINT; } break;
        case NETWORK_RESULT_SIZE_IS_OK: { return NETWORK_RESULT_SIZE_IS_OK_HINT; } break;
        case NETWORK_RESULT_SIZE_IS_EMPTY: { return NETWORK_RESULT_SIZE_IS_EMPTY_HINT; } break;
        case NETWORK_RESULT_RESPONSE_IS_OK: { return NETWORK_RESULT_RESPONSE_IS_OK_HINT; } break;
        case NETWORK_RESULT_RESPONSE_IS_FAIL: { return NETWORK_RESULT_RESPONSE_IS_FAIL_HINT; } break;
        case NETWORK_RESULT_REQUEST_OK: { return NETWORK_RESULT_REQUEST_OK_HINT; } break;
        case NETWORK_RESULT_REQUEST_ERROR_OR_FAIL: { return NETWORK_RESULT_REQUEST_ERROR_OR_FAIL_HINT; } break;
        case NETWORK_RESULT_CONNECTION_OK: { return NETWORK_RESULT_CONNECTION_OK_HINT; } break;
        case NETWORK_RESULT_CONNECTION_FAIL: { return NETWORK_RESULT_CONNECTION_FAIL_HINT; } break;
        case NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK: { return NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK_HINT; } break;
        case NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL: { return NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL_HINT; } break;
        default: { return NETWORK_RESULT_UNDEFINED_HINT; } break;
    }
}

/**
 * @brief libprge core network manager node class
 * 
 * @note use for managing project network
 * @note there should be only one node under "/root" node
 */
class CCoreNetworkManager : public Node
{
    GDCLASS(CCoreNetworkManager, Node);
private:
    /* data */

protected:
    static void _bind_methods();

public:
    CCoreNetworkManager(/* args */);
    ~CCoreNetworkManager();

    //////////////////////////////////////////////////////

    /**
     * @brief make http request
     * 
     * @param url e.g. http://domain.tld ( do not include endpoint as slash, i.e. http://domain.tld/ )
     * @param endpoint e.g. /v1/sign-in
     * @param method 
     * @param headers e.g. {"content-type: multipart/form-data"}
     * @param byteData byte data to pass
     * @param stringData string response result to pass
     * @param delay delay when make poll, default 90 ms
     * @return ENetworkResult
     */
    ENetworkResult makeHttpRequest(String url, String endpoint, HTTPClient::Method method, PackedStringArray headers, PackedByteArray byteData, String stringData, const i32 delay = 90);

    //////////////////////////////////////////////////////

    /**
     * @brief tell if this is CCoreNetworkManager class
     * 
     * @return true 
     * @return false 
     */
    bool isCCoreNetworkManager() { return true; }
};

// default class name for CCoreNetworkManager
inline static cchar *CCoreNetworkManager_CLASS = "CCoreNetworkManager";

#endif // LIBPRGE_CORE_NETWORK_MANAGER_HH
