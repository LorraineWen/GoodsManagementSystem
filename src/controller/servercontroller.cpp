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
    addrlen = sizeof(address);
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
            std::cerr<<"socket failed"<<std::endl;
            exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        std::cerr<<"setsocket failed"<<std::endl;
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }   
}
void ServerController::handle()
{
    char buffer[MAXBUFFER] = {0};
    int valread = read(new_socket, buffer, MAXBUFFER);
        std::cout<<"已经接收连接"<<new_socket<<std::endl;
        if (valread > 0) 
        {
            try 
            {
                nlohmann::json jsonbuffer = nlohmann::json::parse(buffer);
                std::string cmd=jsonbuffer["cmd"];
                nlohmann::json goodsdata=jsonbuffer["goods"];
                std::string name=nlohmann::json::string_t(goodsdata["name"]);
                int price=nlohmann::json::number_integer_t(goodsdata["price"]);
                int number=nlohmann::json::number_integer_t(goodsdata["number"]);
                Goods goods(name,price,number);
                if(cmd=="add")
                {
                    AddGoodsController add;
                    add.addgoodscontroller(new_socket,goods);
                }
                else if(cmd=="delete")
                {
                    DeleteGoodsController del;
                    del.deletegoodscontroller(new_socket,goods.getName());
                }
                else if(cmd=="update")
                {
                    UpdateGooodsController update;
                    update.updategoodscontroller(new_socket,goods);
                }
                else if(cmd=="query")
                {
                    QueryGoodsController query;
                    query.querygoodscontroller(new_socket,goods.getName());
                }
            } 
            catch (const nlohmann::json::parse_error& e) 
            {
                std::cerr << "JSON parse error: " << e.what() << std::endl;
            }
        } 
        memset(buffer, 0, sizeof(buffer));
}
void ServerController::loop()
{
    while(true) 
    {
        if (listen(server_fd, 100) < 0) 
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        std::thread t(&ServerController::handle,this);//由于成员函数的调用必须依赖于对象，如果不，就需要使用类的范围解析符
        t.detach();
    }
}
