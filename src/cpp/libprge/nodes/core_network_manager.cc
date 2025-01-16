#include "core_network_manager.hh"

VARIANT_ENUM_CAST(ENetworkResult);

void CCoreNetworkManager::_bind_methods()
{
    // base bind
    {
        BIND_ENUM_CONSTANT(NETWORK_RESULT_UNDEFINED);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_OK);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_ERROR);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_DOESNT_EXISTS);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_FOUND);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_NOT_FOUND);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_SIZE_IS_OK);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_SIZE_IS_EMPTY);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_RESPONSE_IS_OK);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_RESPONSE_IS_FAIL);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_REQUEST_OK);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_REQUEST_ERROR_OR_FAIL);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_CONNECTION_OK);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_CONNECTION_FAIL);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_CONNECTING_AND_RESOLVING_OK);
        BIND_ENUM_CONSTANT(NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL);
    }

    // extend functions
    {
        ClassDB::bind_method(D_METHOD("makeHttpRequest", "url", "endpoint", "method", "headers", "byteData", "stringData", "delay"), &CCoreNetworkManager::makeHttpRequest);
    }
}

CCoreNetworkManager::CCoreNetworkManager()
{
}

CCoreNetworkManager::~CCoreNetworkManager()
{
}

ENetworkResult CCoreNetworkManager::makeHttpRequest(String url, String endpoint, HTTPClient::Method method, PackedStringArray headers, PackedByteArray byteData, String stringData, const i32 delay)
{
    ENetworkResult result = NETWORK_RESULT_UNDEFINED;

    try
    {
        auto pOS = OS::get_singleton();
        Ref<HTTPClient> pHttp = memnew(HTTPClient);

        // checking connection
        if (pHttp->connect_to_host(url) != OK)
        {
            result = NETWORK_RESULT_CONNECTION_FAIL;
        }

        // do something when connecting or resolving
        while (pHttp->get_status() == HTTPClient::Status::STATUS_CONNECTING || pHttp->get_status() == HTTPClient::Status::STATUS_RESOLVING)
        {
            pHttp->poll();
            if (delay > 0) { pOS->delay_msec(delay); }
        }

        // check if connected
        if (pHttp->get_status() != HTTPClient::Status::STATUS_CONNECTED)
        {
            result = NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL;
            console::error("\"", url, endpoint, "\": ", ENetworkResultAsString(result));
        }

        // check if request is ok
        if (pHttp->request(method, endpoint, headers) != Error::OK)
        {
            result = NETWORK_RESULT_REQUEST_ERROR_OR_FAIL;
            console::error("\"", url, endpoint, "\": ", ENetworkResultAsString(result));
            return result;
        }

        // do something while requesting
        while (pHttp->get_status() == HTTPClient::Status::STATUS_REQUESTING)
        {
            pHttp->poll();
            if (delay > 0) { pOS->delay_msec(delay); }
        }

        // check if has response
        if (pHttp->has_response())
        {
            // when not ok, check the status code
            if (pHttp->get_response_code() != 200)
            {
                result = NETWORK_RESULT_RESPONSE_IS_FAIL;
                console::error("\"", url, endpoint, "\": ", ENetworkResultAsString(result));
            }

            bool dataChunk = false;
            
            // do something when status body exists
            while (pHttp->get_status() == HTTPClient::Status::STATUS_BODY)
            {
                pHttp->poll();
                PackedByteArray chunk = pHttp->read_response_body_chunk();

                if (chunk.size() > 0)
                {
                    byteData = byteData + chunk;
                    dataChunk = true;
                }
            }

            // wheter the response ok, check data size and assign to string data from body
            if (dataChunk && byteData.size() > 0)
            {
                stringData = byteData.get_string_from_ascii();
                result = NETWORK_RESULT_OK;
            }
            else
            {
                result = NETWORK_RESULT_SIZE_IS_EMPTY;
            }
        }

        pHttp->close();
    }
    catch(const std::exception& e)
    {
        console::error("CCoreNetworkManager::makeHttpRequest ERROR as \"", e.what(), "\"");

        result = NETWORK_RESULT_ERROR;
    }

    return result;
}
