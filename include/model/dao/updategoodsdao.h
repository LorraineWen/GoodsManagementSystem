#ifndef UPDATEGOODSDAO_HEADER
#define UPDATEGOODSDAO_HEADER
#include"../models/goods.h"
class UpdateGoodsDao
{
    public:
        UpdateGoodsDao();
        ~UpdateGoodsDao();
        bool updategoodsdao(const Goods& oldgoods,const Goods& newgoods);
};
#endif