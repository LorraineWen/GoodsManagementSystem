#ifndef DATABASECONNECTORTOOL_HEADER
#define DATABASECONNECTORTOOL_HEADER
#include<mysql_driver.h>
#include<mysql_connection.h>
#include<cppconn/statement.h>
#include<cppconn/prepared_statement.h>
class DatabaseConnector
{
    public:
    static sql::Connection *getDatabaseConnector();
    private:
        DatabaseConnector();
        ~DatabaseConnector();
        static DatabaseConnector *databaseconn;
        sql::Driver *driver;
        sql::Connection *con;
};
#endif