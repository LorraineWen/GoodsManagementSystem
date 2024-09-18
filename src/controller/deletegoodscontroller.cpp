#include"../../include/controller/deletegoodscontroller.h"
#include<sys/socket.h>
#include<unistd.h>
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
        printf("成功删除商品\n");
    }
    nlohmann::json replyjson;
    replyjson["code"]=res;
    std::string replystr=replyjson.dump();
    res=send(clientfd,replystr.c_str(),replystr.length(),0);
    if(res==-1)
    {
        perror("deletecfd send error");
    }
}