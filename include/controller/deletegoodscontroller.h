#ifndef DELETEGOODSCONTROLLER_HEADER
#define DELETEGOODSCONTROLLER_HEADER
#include"../model/dao/deletegoodsdao.h"
#include<nlohmann/json.cpp>
class DeleteGoodsController
{
public:
    DeleteGoodsController();
    ~DeleteGoodsController();
    void deletegoodscontroller(int& clientfd,const std::string& name);
};
#endif