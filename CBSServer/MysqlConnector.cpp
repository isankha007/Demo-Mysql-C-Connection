/*
 * Example to connect to MariaDB(MySQL)
 */
#include <iostream>
#include "MysqlConnector.h"  // require libmysqlclient-dev
#include <string>
#include <mysql/mysql.h>

using namespace std;
MysqlDatabase* MysqlDatabase::singlatone;

/*
 * [CLASS] Process
 */
//class Proc
//{
//
//};

/*
 * Proc - Constructor
 */
MysqlDatabase::MysqlDatabase()
{
    // Initialize constants
    MY_HOSTNAME = "localhost";
    MY_DATABASE = "cbs_db";
    MY_USERNAME = "sankha";
    MY_PASSWORD = "sankha@123";
    MY_SOCKET   = NULL;

}

/*
 * Main Process
 */
bool MysqlDatabase::execMain(char sqlstr[])
{
    try {
        // Format a MySQL object
        conn = mysql_init(NULL);

        // Establish a MySQL connection
        if (!mysql_real_connect(
                conn,
                MY_HOSTNAME, MY_USERNAME,
                MY_PASSWORD, MY_DATABASE,
                MY_PORT_NO, MY_SOCKET, MY_OPT)) {
            cerr << mysql_error(conn) << endl;
            return false;
        }

        // Execute a sql statement
        //char sqlstr[50]= "call agent_call('Bangalore')";//"SHOW TABLES";
        if (mysql_query(conn, sqlstr)) {
            cerr << mysql_error(conn) << endl;
            return false;
        }

        // Get a result set
        res = mysql_use_result(conn);

        // Fetch a result set
        cout << "* MySQL - SHOW TABLES in `"
             << MY_DATABASE << "`" << endl;
        while ((row = mysql_fetch_row(res)) != NULL)
            cout << row[0] <<" "<<row[1]<< endl;

        // Release memories
        mysql_free_result(res);

        // Close a MySQL connection
        mysql_close(conn);
    } catch (char *e) {
        cerr << "[EXCEPTION] " << e << endl;
        return false;
    }
    return true;
}

/*
 * Execution
 */
//int main(){
//    try {
//        Proc objMain;
//        bool bRet = objMain.execMain();
//        if (!bRet) cout << "ERROR!" << endl;
//    } catch (char *e) {
//        cerr << "[EXCEPTION] " << e << endl;
//        return 1;
//    }
//    return 0;
//}
