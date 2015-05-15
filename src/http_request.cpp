#include "http_request.h"

namespace lftnet {

HttpRequest::HttpRequest(const lftnet::Url& url) : m_url(url), m_method("GET") {
}

HttpRequest::operator std::string() {
  std::stringstream req_str;
  req_str << "GET " << m_url.Path() << " HTTP/1.1\n";
  req_str << "Host: " << m_url.Host() << "\n";
  req_str << "Content-Length: 0";
  req_str << "\r\n\r\n";
  return req_str.str();
}

}
