#ifndef QUERYGOODSDAO_HEADER
#define QUERYGOODSDAO_HEADER
#include"../models/goods.h"
#include<string>
class QueryGoodsDao
{
    public:
        QueryGoodsDao();
        ~QueryGoodsDao();
        Goods querygoodsdao(std::string name);
};
#endif