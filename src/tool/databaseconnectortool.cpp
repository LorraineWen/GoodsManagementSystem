#include"../../include/tool/databaseconnectortool.h"
DatabaseConnector* DatabaseConnector::databaseconn=new DatabaseConnector();
sql::Connection* DatabaseConnector::getDatabaseConnector()
{
    return databaseconn->con;
}
DatabaseConnector::DatabaseConnector()
{
    driver=get_driver_instance();
    con=driver->connect("tcp://localhost:3306", "root", "2145901423LxL@");
}
DatabaseConnector::~DatabaseConnector()
{
    // if(con&&databaseconn) 
    // {
    //     con->close();
    //     delete con;
    //     delete databaseconn;
    //     con=nullptr;
    //     databaseconn=nullptr;
    // }
}