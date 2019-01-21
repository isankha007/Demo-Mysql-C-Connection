#include <mysql/mysql.h>
#include<string>
using namespace std;
class MysqlDatabase{
private:
	const char* MY_HOSTNAME;
	    const char* MY_DATABASE;
	    const char* MY_USERNAME;
	    const char* MY_PASSWORD;
	    const char* MY_SOCKET;
	    enum {
	        MY_PORT_NO = 3306,
	        MY_OPT     = 0
	    };
	    MYSQL     *conn;
	    MYSQL_RES *res;
	    MYSQL_ROW row;
	    static MysqlDatabase *singlatone;

	public:
	    MysqlDatabase();           // Constructor
	    bool execMain(char sqlstr[]);  // Main Process
		void ExecuteQueryForaccountDetail(string q);


};
