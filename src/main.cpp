#include "tcp_socket.h"
#include "url.h"
#include "http_request.h"
#include "http_client.h"
#include "http_parser.h"

namespace lftnet {

}

int main(int argc, char *argv[]) {
  lftnet::HttpRequest req(lftnet::Url("http://media.lofti.li/txt.txt"));
  lftnet::HttpClient client;
  client.Send(req);
};
