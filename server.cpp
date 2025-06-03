#include "server.hpp"
#include <iostream>

namespace BinaryDB {

Server::Server(unsigned short port)
    : acceptor_(io_context_, {boost::asio::ip::tcp::v4(), port}) {}

void Server::run() {
    do_accept();
    io_context_.run();
}

void Server::do_accept() {
    acceptor_.async_accept([this](auto ec, auto socket) {
        if (!ec) {
            std::thread(&Server::handle_client, this, std::move(socket)).detach();
        }
        do_accept();
    });
}

void Server::handle_client(boost::asio::ip::tcp::socket socket) {
    try {
        for (;;) {
            uint32_t size;
            boost::asio::read(socket, boost::asio::buffer(&size, sizeof(size)));

            std::vector<char> buffer(size);
            boost::asio::read(socket, boost::asio::buffer(buffer));

            Request req;
            if (!req.ParseFromArray(buffer.data(), size)) continue;

            Response resp;
            if (req.has_set()) {
                storage_.set(req.set().key(), req.set().value());
                resp.mutable_status()->set_success(true);
            } else if (req.has_get()) {
                auto value = storage_.get(req.get().key());
                if (value) {
                    resp.mutable_get()->set_value(*value);
                    //resp.mutable_status()->set_success(true);
                } else {
                    resp.mutable_status()->set_success(false);
                }
            }

            std::string out;
            resp.SerializeToString(&out);
            uint32_t out_size = static_cast<uint32_t>(out.size());
            boost::asio::write(socket, boost::asio::buffer(&out_size, sizeof(out_size)));
            boost::asio::write(socket, boost::asio::buffer(out));
        }
    } catch (...) {
        // client disconnected
    }
}

} // namespace BinaryDB
