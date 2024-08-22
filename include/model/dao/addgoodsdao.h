#ifndef ADDGOODSDAO_HEADER
#define ADDGOODSDAO_HEADER
#include"../models/goods.h"
class AddGoodsDao
{
    public:
        AddGoodsDao();
        ~AddGoodsDao();
        bool addgoodsdao(const Goods &goods)const;
};
#endif