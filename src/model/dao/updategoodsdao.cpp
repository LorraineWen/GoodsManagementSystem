#include"../../../include/model/dao/updategoodsdao.h"
#include"../../../include/tool/databaseconnectortool.h"
#include<memory>
UpdateGoodsDao::UpdateGoodsDao()
{

}
UpdateGoodsDao::~UpdateGoodsDao()
{

}
bool UpdateGoodsDao::updategoodsdao(const Goods& oldgoods,const Goods& newgoods)
{
    bool res=false;
    try
    {
        std::string sql="update goodssystem.goods set name=?,price=?,number=? where name=?";
        std::unique_ptr<sql::PreparedStatement>pstat(DatabaseConnector::getDatabaseConnector()->prepareStatement(sql));
        int price=newgoods.getPrice();
        int number=newgoods.getNumber();
        if(price==-1)price=oldgoods.getPrice();
        if(number==-1)number=oldgoods.getNumber();
        pstat->setString(1,newgoods.getName());
        pstat->setInt(2,price);
        pstat->setInt(3,number);
        pstat->setString(4,oldgoods.getName());
        pstat->executeUpdate();
        res=true;
    }
    catch(const sql::SQLException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return res;
}