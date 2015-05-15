#include "url.h"

namespace lftnet {

Url::Url(const char* url_string) {
  m_host = "127.0.0.1";
  m_path = "/system";
  m_protocol = "http";
  m_port = 1337;
}

}
