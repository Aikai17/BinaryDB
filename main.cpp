#include "server.hpp"

int main() {
    BinaryDB::Server server(12345);
    server.run();
    return 0;
}
