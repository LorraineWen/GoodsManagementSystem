#include"../../../include/model/dao/deletegoodsdao.h"
#include"../../../include/tool/databaseconnectortool.h"
#include<memory>
DeleteGoodsDao::DeleteGoodsDao()
{

}
DeleteGoodsDao::~DeleteGoodsDao()
{
    
}
bool DeleteGoodsDao::deletegoodsdao(const std::string name)
{
    bool res=false;
    try
    {
       std::string sql="delete from goodssystem.goods where name=?";
       std::unique_ptr<sql::PreparedStatement>pstat(DatabaseConnector::getDatabaseConnector()->prepareStatement(sql));
       pstat->setString(1,name);
       pstat->executeUpdate();
       res=true;
    }
    catch(const sql::SQLException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return res;
}