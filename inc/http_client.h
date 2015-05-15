#ifndef _LFTNET_HTTP_CLIENT_H
#define _LFTNET_HTTP_CLIENT_H

#include <vector>
#include "tcp_socket.h"
#include "http_request.h"
#include "http_parser.h"
#include "http_response.h"

namespace lftnet {

class HttpClient {
  public:
    HttpClient() = default;
    HttpClient(const HttpClient&) = default;
    ~HttpClient() = default;
    HttpClient& operator=(const HttpClient&) = default;
    bool Send(HttpRequest&);
    std::shared_ptr<lftnet::HttpResponse> Latest();
  private:
    lftnet::HttpParser m_parser;
    std::vector< std::shared_ptr<lftnet::HttpResponse> > m_responses;
};

}

#endif
