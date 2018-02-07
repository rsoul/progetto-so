#ifndef WEBSOCKET_HPP
#define WEBSOCKET_HPP

#include "include/errors.hpp"
#include "include/network.hpp"
#include "include/base64/base64.h"
#include "include/sha1/sha1.h"

#include "responde.hpp"
#include "request.hpp"
#include "Frame.hpp"
#include "Callback.hpp"

#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define RFC6455_KEY_GUID               "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"           // RFC 6455 Magic GUID

namespace ws 
{
class WebSocket{
    
    int m_server;
    int m_client;
    struct sockaddr_in* m_server_addr;
    struct sockaddr_in* m_client_addr;

    bool m_running;

    pthread_t* pool[];

    protected:
        std::string m_host;
        std::string m_origini;
        std::string m_protocol;
        std::string m_key;
        std::string m_accept;

        void ParseHandshake();
        virtual void Handshake();
    
    public:
        WebSocket();
        virtual ~WebSocket();
        std::string AcceptKey();
        std::string AcceptKey(std::string original);

        virtual void listen();
        virtual void  Send(std::string message);
        void stop();
};
}
#endif