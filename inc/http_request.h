#ifndef _LFTNET_HTTP_REQUEST_H
#define _LFTNET_HTTP_REQUEST_H

#include <iostream>
#include <sstream>
#include "url.h"
#include "tcp_socket.h"

namespace lftnet {

class HttpRequest {
  public:
    HttpRequest(const HttpRequest&) = default;
    HttpRequest& operator=(const HttpRequest&) = default;
    ~HttpRequest() = default;

    HttpRequest(const Url&);
    operator std::string();
    const lftnet::Url& Url() { return m_url; }

  private:
    lftnet::Url m_url;
    std::string m_method;
};

}

#endif
