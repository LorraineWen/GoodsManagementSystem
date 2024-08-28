#include"../../include/controller/querygoodscontroller.h"
#include<iostream>
#include<nlohmann/json.cpp>
#include<sys/socket.h>
QueryGoodsController::QueryGoodsController()
{

}
QueryGoodsController::~QueryGoodsController()
{

}
void QueryGoodsController::querygoodscontroller(int& clientfd,const std::string& name)
{
    int res=-1;
    QueryGoodsDao query;
    Goods goods=query.querygoodsdao(name);
    if(goods.getName()!="")
    {
        res=1;
        std::cout<<"查询商品成功"<<std::endl;
    }
    nlohmann::json replyjson;
    replyjson["code"]=res;
    nlohmann::json goodsjson;
    goodsjson["name"]=goods.getName();
    goodsjson["price"]=goods.getPrice();
    goodsjson["number"]=goods.getNumber();
    replyjson["goods"]=goodsjson;
    std::string replystr=replyjson.dump();
    send(clientfd,replystr.c_str(),replystr.length(),0);
}