#include"../../include/controller/servercontroller.h"
#include<iostream>
#include <nlohmann/json.cpp>
#include<thread>
ServerController::ServerController()
{

}
ServerController::~ServerController()
{

}
void ServerController::init()
{
    int opt=1;
    port=8989;
    saddrlen = sizeof(saddr);
    sfd=socket(AF_INET,SOCK_STREAM,0);
    if (sfd==-1) 
    {
        perror("socket error");
    }
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(port);
    flags=bind(sfd, (struct sockaddr *)&saddr,saddrlen);
    if (flags==-1) 
    {
        perror("bind error");
    } 
}
void ServerController::handle()
{
    int clientfd=cfd;
    while(true)
    {
        memset(rbuffer, 0, sizeof(rbuffer));
        flags= recv(clientfd, rbuffer, MAXBUFFER,0);
        if(flags==-1)
        {
            perror("recv error");
        }
        else if(flags==0)
        {
            printf("对端断开连接\n");
            close(clientfd);
            break;
        }
        else
        {
            try 
            {
                nlohmann::json jsonbuffer = nlohmann::json::parse(rbuffer);
                std::string cmd=jsonbuffer["cmd"];
                nlohmann::json goodsdata=jsonbuffer["goods"];
                std::string name=nlohmann::json::string_t(goodsdata["name"]);
                int price=nlohmann::json::number_integer_t(goodsdata["price"]);
                int number=nlohmann::json::number_integer_t(goodsdata["number"]);
                Goods goods(name,price,number);
                if(cmd=="add")
                {
                    AddGoodsController add;
                    add.addgoodscontroller(clientfd,goods);
                }
                else if(cmd=="delete")
                {
                    DeleteGoodsController del;
                    del.deletegoodscontroller(clientfd,goods.getName());
                }
                else if(cmd=="update")
                {
                    UpdateGooodsController update;
                    update.updategoodscontroller(clientfd,goods);
                }
                else if(cmd=="query")
                {
                    QueryGoodsController query;
                    query.querygoodscontroller(clientfd,goods.getName());
                }
            } 
            catch (const nlohmann::json::parse_error& e) 
            {
                std::cerr << "JSON parse error: " << e.what() << std::endl;
            }
        }
    }
}
void ServerController::loop()
{
    flags=listen(sfd, 100);
    if(flags==-1)
    {
        perror("listen error");
    }  
    while(true) 
    {
        struct sockaddr_in caddr;
        int caddrlen=sizeof(caddr);
        cfd=accept(sfd, (struct sockaddr *)&caddr, (socklen_t*)&caddrlen);
        if (cfd==-1) 
        {
            perror("accept error");
        }
        std::thread t(&ServerController::handle,this);//必须加上this
        t.detach();
    }
}
