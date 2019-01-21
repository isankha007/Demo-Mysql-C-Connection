#include"MysqlConnector.cpp"
int main(int argc, char **argv) {
	 try {
	        MysqlDatabase objMain;
	        char sqlstr[50]="SELECT * from agents"; //"call agent_call('Bangalore')";
	        bool bRet = objMain.execMain(sqlstr);
	        if (!bRet) cout << "ERROR!" << endl;
	    } catch (char *e) {
	        cerr << "[EXCEPTION] " << e << endl;
	        return 1;
	    }
	return 0;
}
