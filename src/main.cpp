#include "tcp_socket.h"
#include "url.h"
#include "http_request.h"
#include "http_client.h"
#include "http_parser.h"
#include "http_response.h"

namespace lftnet {

}

int main(int argc, char *argv[]) {
  if(argc < 2) return 0;

  const char *url_str = argv[1];
  lftnet::Url url = url_str;
  lftnet::HttpRequest req(url);
  lftnet::HttpClient client;

  if(client.Send(req)) {
    std::shared_ptr<lftnet::HttpResponse> res = client.Latest();
    std::cout << res->Body() << std::endl;
  }
};
