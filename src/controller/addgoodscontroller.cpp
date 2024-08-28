#include"../../include/controller/addgoodscontroller.h"
#include<sys/socket.h>
#include<iostream>
AddGoodsController::AddGoodsController()
{

}
AddGoodsController::~AddGoodsController()
{

}
void AddGoodsController::addgoodscontroller(int& clientfd,const Goods& goods)
{
    int res=-1;
    AddGoodsDao add;
    if(add.addgoodsdao(goods))
    {
        res=1;
        std::cout<<"成功添加商品"<<std::endl;
    }
    nlohmann::json replydata;
    replydata["code"]=res;
    std::string replystr=replydata.dump();
    send(clientfd,replystr.c_str(),replystr.length(),0);
}