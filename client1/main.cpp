#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <nlohmann/json.cpp>
#include<iostream>
#define PORT 8989
#define MAXBUFFER 1024

using json = nlohmann::json;

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAXBUFFER] = {0};

    // 创建套接字
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 连接到服务器
    while(true)
    {
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
    }
    else
    {
        break;
    }
    std::cout<<"尝试再次连接"<<std::endl;
    }
    while(true)
    {
    // 构造 JSON 请求
    json request;
    request["cmd"] = "query";
    json goods;
    goods["name"]="hello";
    goods["price"]=200;
    goods["number"]=1;
    request["goods"]=goods;
    std::string req_str = request.dump();
    // 发送请求
    send(sock, req_str.c_str(), req_str.length(), 0);
    printf("JSON request sent\n");
    int cnt=recv(sock,buffer,MAXBUFFER,0);
    if(cnt>0)
    {
    json reply=json::parse(buffer);
    std::cout<<reply["code"]<<std::endl;
    json goods=reply["goods"];
    std::string name=goods["name"];
    int price=goods["price"];
    int number=goods["number"];
    std::cout<<"name:"<<name<<"price:"<<price<<"number:"<<number<<std::endl;
    }
    }
    return 0;
}
