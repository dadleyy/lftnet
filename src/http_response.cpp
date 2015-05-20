#include "http_response.h"

namespace lftnet {

HttpResponse::HttpResponse(const char* data) {
  char *header_break = strstr(data, "\r\n\r\n");
  int head_size = header_break - data,
      content_length = -1;

  std::stringstream header_reader(std::string(data, head_size));
  std::string line;
  while(std::getline(header_reader, line) && line != "\r") {
    int split = line.find(':', 0);

    if(split > line.size()  - 2 || split == 0)
      continue;

    std::string key = line.substr(0, split),
                val = line.substr(split + 2);

    if(key == "Content-Length")
      content_length = std::stoi(val);

    m_headers.push_back(std::make_pair(key, val));
  }

  m_body.resize(content_length);
  memcpy(&m_body[0], &data[head_size + 4], content_length * sizeof(unsigned char));
}

}
