#ifndef QUERYGOODSCONTROLLER_HEADER
#define QUERYGOODSCONTROLLER_HEADER
#include"../model/dao/querygoodsdao.h"
class QueryGoodsController
{
public:
    QueryGoodsController();
    ~QueryGoodsController();
    void querygoodscontroller(int& clientfd,const std::string& name);
};
#endif