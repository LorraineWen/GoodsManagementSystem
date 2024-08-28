#ifndef SERVERTOOL_HEADER
#define SERVERTOOL_HEADER
#define PORT 8989
#define MAXBUFFER 1024
#define MAX_EVENTS 1024
#include<sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/epoll.h>
#include<sys/eventfd.h>
#include"../../include/controller/addgoodscontroller.h"
#include"../../include/controller/deletegoodscontroller.h"
#include"../../include/controller/updategoodscontroller.h"
#include"../../include/controller/querygoodscontroller.h"
class ServerController
{
    public:
        ServerController();
        ~ServerController();
        void init();
        void handle();
        void loop();
    private:
    int server_fd;
    int new_socket;
    struct sockaddr_in address;
    int addrlen;
    struct epoll_event events[MAX_EVENTS];
    int epoll_fd;
    struct epoll_event event;
};
#endif