#ifndef ADDGOODSCONTROLLER_HEADER
#define ADDGOODSCONTROLLER_HEADER
#include"../../include/model/dao/addgoodsdao.h"
#include<nlohmann/json.cpp>
class AddGoodsController
{
    public:
        AddGoodsController();
        ~AddGoodsController();
        void addgoodscontroller(int& clientfd,const Goods& goods);
};
#endif