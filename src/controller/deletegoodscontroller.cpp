#include"../../include/controller/deletegoodscontroller.h"
#include<sys/socket.h>
#include<iostream>
DeleteGoodsController::DeleteGoodsController()
{

}
DeleteGoodsController::~DeleteGoodsController()
{

}
void DeleteGoodsController::deletegoodscontroller(int& clientfd,const std::string& name)
{
    int res=-1;
    DeleteGoodsDao del;
    if(del.deletegoodsdao(name))
    {
        res=1;
        std::cout<<"成功删除商品"<<std::endl;
    }
    nlohmann::json replyjson;
    replyjson["code"]=res;
    std::string replystr=replyjson.dump();
    send(clientfd,replystr.c_str(),replystr.length(),0);
}