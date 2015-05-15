#ifndef _LFTNET_HTTP_PARSER_H
#define _LFTNET_HTTP_PARSER_H

#include <vector>
#include <iostream>
#include <sstream>
#include <memory.h>
#include "tcp_socket.h"

namespace lftnet {

class HttpParser {
  public:
    HttpParser();
    HttpParser& operator<<(lftnet::TcpSocket&);
  private:
    class Impl {
      public:
        Impl();
        ~Impl();
        void Read(lftnet::TcpSocket&);
        bool Receiving();
      private:
        void UpdateState();
        void FindContentLength();

        char *m_data;
        int m_size;
        int m_content_size;
        enum {
          RECEIVING_STATE_HEADERS,
          RECEIVING_STATE_BODY,
          RECEIVING_STATE_FINISHED,
          RECEIVING_STATE_ERRORED
        } m_state;
    };
    std::unique_ptr<lftnet::HttpParser::Impl> m_impl;
};

}

#endif
