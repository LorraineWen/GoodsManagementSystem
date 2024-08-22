#include"../../../include/model/dao/addgoodsdao.h"
#include"../../../include/tool/databaseconnectortool.h"
#include<string>
#include<memory>
AddGoodsDao::AddGoodsDao()
{

}
AddGoodsDao::~AddGoodsDao()
{

}
bool AddGoodsDao::addgoodsdao(const Goods &goods)const
{
    bool res=false;
    try
    {
        std::string sql="insert into goodssystem.goods (name,price,number)values(?,?,?);";
        std::unique_ptr<sql::PreparedStatement>pstat(DatabaseConnector::getDatabaseConnector()->prepareStatement(sql));
        int price=goods.getPrice();
        int number=goods.getNumber();
        if(price==-1)price=0;
        if(number==-1)number=0;
        pstat->setString(1,goods.getName());
        pstat->setInt(2,price);
        pstat->setInt(3,number);
        pstat->executeUpdate();
        res=true;
    }
    catch(const sql::SQLException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return res;
}