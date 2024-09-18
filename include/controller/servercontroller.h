#ifndef SERVERTOOL_HEADER
#define SERVERTOOL_HEADER
#define MAXBUFFER 1024
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
    int sfd;
    int cfd;
    struct sockaddr_in saddr;
    int saddrlen;;
    int port;
    int flags;
    char rbuffer[MAXBUFFER];
};
#endif