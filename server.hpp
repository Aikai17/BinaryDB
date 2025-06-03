#pragma once
#include "storage.hpp"
#include "proto/db.pb.h"
#include <boost/asio.hpp>
#include <thread>

namespace BinaryDB {
class Server {
public:
    Server(unsigned short port);
    void run();

private:
    void do_accept();
    void handle_client(boost::asio::ip::tcp::socket socket);

    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
    Storage storage_;
};
}
