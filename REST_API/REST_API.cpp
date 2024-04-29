#include "HTTPServer.h"

int main()
{
    HttpServer::UPtr server = std::make_unique<HttpServer>();

    server->Start(8080);

    return 0;
}