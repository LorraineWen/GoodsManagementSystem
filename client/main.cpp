#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <nlohmann/json.cpp>
#include<iostream>
#define PORT 8989
#define MAXBUFFER 1024
using json = nlohmann::json;
int main() 
{
    int flags;
    struct sockaddr_in caddr;
    char buffer[MAXBUFFER] = {'\0'};
    int port=8989;
    int cfd=socket(AF_INET, SOCK_STREAM, 0);
    if (cfd==-1) {
        perror("socket error");
        exit(1);
    }
    caddr.sin_family = AF_INET;
    caddr.sin_port= htons(PORT);
    int ip;
    socklen_t iplen=sizeof(ip);
    flags=inet_pton(AF_INET,"192.168.101.231",&ip);
    if(flags==-1)
    {
        perror("inet_pton error");
        exit(1);
    }
    caddr.sin_addr.s_addr=ip;
    flags=connect(cfd, (struct sockaddr *)&caddr, sizeof(caddr));
    if(flags==-1)
    {
        perror("connect error");
    }
    while(true)
    {
        json request;
        request["cmd"] = "query";
        json goods;
        goods["name"]="hello";
        goods["price"]=200;
        goods["number"]=1;
        request["goods"]=goods;
        std::string req_str = request.dump();
        flags=send(cfd, req_str.c_str(), req_str.length(), 0);
        if(flags==-1)
        {
            perror("send error");
            continue;
        }
        printf("JSON request sent\n");
        flags=recv(cfd,buffer,MAXBUFFER,0);
        if(flags==-1)
        {
            perror("recv error");
            continue;
        }
        else if(flags==0)
        {
            perror("连接断开");
        }
        json reply=json::parse(buffer);
        std::cout<<reply["code"]<<std::endl;
        goods=reply["goods"];
        std::string name=goods["name"];
        int price=goods["price"];
        int number=goods["number"];
        std::cout<<"name:"<<name<<" price:"<<price<<" number:"<<number<<std::endl;
        sleep(1);
    }
    close(cfd);
    return 0;
}
