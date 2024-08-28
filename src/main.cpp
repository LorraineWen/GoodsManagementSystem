#include"../include/controller/servercontroller.h"
int main() 
{
    ServerController server;
    server.init();
    server.loop();
    return 0;
}