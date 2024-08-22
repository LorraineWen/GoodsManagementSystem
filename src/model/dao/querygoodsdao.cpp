#include"../../../include/model/dao/querygoodsdao.h"
#include"../../../include/tool/databaseconnectortool.h"
QueryGoodsDao::QueryGoodsDao()
{

}
QueryGoodsDao::~QueryGoodsDao()
{

}
Goods QueryGoodsDao::querygoodsdao(std::string name)
{
    Goods goods;
    try
    {
        std::string sql="select * from goodssystem.goods where name=?";
        std::unique_ptr<sql::PreparedStatement>pstat(DatabaseConnector::getDatabaseConnector()->prepareStatement(sql));
        pstat->setString(1,name);
        std::unique_ptr<sql::ResultSet>res(pstat->executeQuery());
        while(res->next())
        {
        goods.setName(res->getString("name"));
        goods.setNumber(res->getInt("number"));
        goods.setPrice(res->getInt("price"));
        }
    }
    catch(const sql::SQLException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return goods;
}