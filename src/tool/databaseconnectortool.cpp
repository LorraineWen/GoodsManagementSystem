#include"../../include/tool/databaseconnectortool.h"
DatabaseConnector DatabaseConnector::databaseconn;
sql::Connection* DatabaseConnector::getDatabaseConnector()
{
    return databaseconn.con;
}
DatabaseConnector::DatabaseConnector()
{
    driver=get_driver_instance();
    con=driver->connect("tcp://localhost:3306", "root", "2145901423LxL@");
}
DatabaseConnector::~DatabaseConnector()
{
    if(con) 
    {
        con->close();
        delete con;
        con=nullptr;
    }
}