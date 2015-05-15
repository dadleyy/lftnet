#include "http_client.h"

namespace lftnet {

int HttpClient::Send(HttpRequest& req) {
  TcpSocket socket;
  socket.Connect(req.Url().Host().c_str(), req.Url().Port());
  std::string request_string(req);
  socket.Write(request_string.c_str(), request_string.size());
  m_parser << socket;
  return 0;
};

}
