#include"../../include/controller/updategoodscontroller.h"
#include<unistd.h>
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
        printf("修改商品成功\n");
    }
    nlohmann::json replyjson;
    replyjson["code"]=res;
    std::string replystr=replyjson.dump();
    res=send(clientfd,replystr.c_str(),replystr.length(),0);
    if(res==-1)
    {
        perror("updatecfd send error");
    }
}