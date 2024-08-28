#include"../../include/controller/updategoodscontroller.h"
#include<iostream>
#include<sys/socket.h>
#include<nlohmann/json.cpp>
UpdateGooodsController::UpdateGooodsController()
{

}
UpdateGooodsController::~UpdateGooodsController()
{

}
void UpdateGooodsController::updategoodscontroller(int& clientfd,const Goods& newgoods)
{
    int res=-1;
    QueryGoodsDao query;
    const Goods oldgoods=query.querygoodsdao(newgoods.getName());
    UpdateGoodsDao update;
    if(update.updategoodsdao(oldgoods,newgoods))
    {
        res=1;
        std::cout<<"修改商品成功"<<std::endl;
    }
    nlohmann::json replyjson;
    replyjson["code"]=res;
    std::string replystr=replyjson.dump();
    send(clientfd,replystr.c_str(),replystr.length(),0);
}