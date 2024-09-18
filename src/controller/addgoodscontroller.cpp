#include"../../include/controller/addgoodscontroller.h"
#include<sys/socket.h>
#include<unistd.h>
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
        printf("成功添加商品\n");
    }
    nlohmann::json replydata;
    replydata["code"]=res;
    std::string replystr=replydata.dump();
    res=send(clientfd,replystr.c_str(),replystr.length(),0);
    if(res==-1)
    {
        perror("cfd send error");
    }
}