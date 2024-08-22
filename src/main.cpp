#include"../include/model/dao/addgoodsdao.h"
#include"../include/model/dao/deletegoodsdao.h"
#include"../include/model/dao/querygoodsdao.h"
#include"../include/model/dao/updategoodsdao.h"
#include<iostream>
int main()
{
    Goods goods("hello",1,10);
    Goods newgoods("newhello",1,10);
    UpdateGoodsDao update;
    update.updategoodsdao(goods,newgoods);
    return 0;
}