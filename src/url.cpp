#include "url.h"

namespace lftnet {

Url::Url(const char* url_string) {
  char *protocol_break = strstr(url_string, "://");
  if(protocol_break == nullptr) return;
  int protocol_size = protocol_break - url_string;
  m_protocol = std::string(url_string, protocol_size);
  char *host_break = strstr(protocol_break + 3, "/");
  int host_size = host_break - (protocol_break + 3);
  if(host_break == nullptr) return;
  m_host = std::string(protocol_break + 3, host_size);
  char *path_break = strchr(host_break, '\0');
  if(path_break == nullptr) return;
  int path_size = path_break - host_break;
  m_path = std::string(host_break, path_size);
  m_port = 80;
}

}
