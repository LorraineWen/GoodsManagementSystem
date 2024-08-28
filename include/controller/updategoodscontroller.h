#ifndef UPDATEGOODSCONTROLLER_HEADER
#define UPDATEGOODSCONTROLLER_HEADER
#include"../model/dao/updategoodsdao.h"
#include"../model/dao/querygoodsdao.h"
class UpdateGooodsController
{
public:
    UpdateGooodsController();
    ~UpdateGooodsController();
    void updategoodscontroller(int& clientfd,const Goods& newgoods);
};
#endif