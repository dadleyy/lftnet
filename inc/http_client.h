#ifndef _LFTNET_HTTP_CLIENT_H
#define _LFTNET_HTTP_CLIENT_H

#include "tcp_socket.h"
#include "http_request.h"
#include "http_parser.h"

namespace lftnet {

class HttpClient {
  public:
    HttpClient() = default;
    HttpClient(const HttpClient&) = default;
    ~HttpClient() = default;
    HttpClient& operator=(const HttpClient&) = default;
    int Send(HttpRequest&);
  private:
    lftnet::HttpParser m_parser;
};

}

#endif
