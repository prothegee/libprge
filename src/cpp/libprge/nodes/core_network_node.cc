#include "core_network_node.hh"

VARIANT_ENUM_CAST(libprge::NETWORK_RESULT);

namespace libprge
{

void CCoreNetworkNode::_bind_methods()
{
    // make http request
    {
        ClassDB::bind_method(D_METHOD("makeHttpRequest", "url", "endpoint", "method", "headers", "byteData", "stringData", "delay"), &CCoreNetworkNode::makeHttpRequest);
    }
}

CCoreNetworkNode::CCoreNetworkNode()
{
    // lastly
    this->set_name(m_defaultName);
}

CCoreNetworkNode::~CCoreNetworkNode()
{
}

NETWORK_RESULT CCoreNetworkNode::makeHttpRequest(String url, String endpoint, HTTPClient::Method method, PackedStringArray headers, PackedByteArray byteData, String stringData, const i32 delay)
{
    NETWORK_RESULT result = NETWORK_RESULT_UNDEFINED;

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
            logger::log::errorAlways("can't connect & resolving host of ", url, endpoint);
            result = NETWORK_RESULT_CONNECTING_AND_RESOLVING_FAIL;
        }

        // check if request is ok
        if (pHttp->request(method, endpoint, headers) != Error::OK)
        {
            return NETWORK_RESULT_REQUEST_ERROR_OR_FAIL;
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
                logger::log::errorAlways("response code is \"", pHttp->get_response_code(), "\"");

                result = NETWORK_RESULT_RESPONSE_IS_FAIL;
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
            }
            else
            {
                result = NETWORK_RESULT_SIZE_IS_EMPTY;
            }
        }

        pHttp->close();

        result = NETWORK_RESULT_OK;
    }
    catch(const std::exception& e)
    {
        logger::log::errorAlways("EXCEPTION as \"", e.what(), "\"");

        result = NETWORK_RESULT_ERROR;
    }

    return result;
}

} // namespace libprge
