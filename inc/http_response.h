#ifndef _LFTNET_HTTP_RESPONSE_H
#define _LFTNET_HTTP_RESPONSE_H

#include <iostream>
#include <vector>
#include <sstream>

namespace lftnet {

class HttpResponse {
  public:
    HttpResponse() = default;
    HttpResponse(const HttpResponse&) = default;
    HttpResponse& operator=(const HttpResponse&) = default;
    HttpResponse(const char*);
    ~HttpResponse() = default;
    const char* Body() { return m_body.data(); };
    int ContentLength() { return m_body.size(); }
  private:
    std::vector< std::pair<std::string, std::string> > m_headers;
    std::vector<char> m_body;
};

}

#endif
