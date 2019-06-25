#ifndef MySQLBase_H
#define MySQLBase_H
#include "driver\mysql_driver.h"
#include "cppconn\sqlstring.h"
#include "cppconn\driver.h"
#include "cppconn\statement.h"
#include "cppconn\prepared_statement.h"
using namespace sql;

enum commit_args{
	CMT_START,
	CMT_COMMIT,
	CMT_ROLLBACK,
};
class MySQLBase{
private:
protected:
	Driver *driver;
	Connection * m_myConn;
	PreparedStatement * m_preStatement;
	Statement * m_statement;
	ResultSet * m_res;
	/*-----------------------------------------
	At first,you should use OpenConnect to GetConnection,
	this function just return the member named m_myConn;
	------------------------------------------*/
	Connection * GetConn();
	PreparedStatement * GetPreStatement();
	Statement * GetStatement();
	ResultSet * GetRes();
	void SetRes(ResultSet *);
	int CheckConnect();
	int SetEncoding(char * encoding);
	/*-----------------------------------------
	int Commit(int mode)
	mode 0 is CMT_START,
	mode 1 is CMT_COMMIT,
	mode 2 is CMT_ROLLBACK
	you will get -1 when your parameter is invalid;
	you will get -2 when your connection is error;
	you will get 0 when it just works;
	-----------------------------------------*/
	int Commit(int mode);
public:

	MySQLBase();
	/*
	Make sure that you free con,
	the sql::Connection object,
	as soon as you do not need it any more.
	But do not explicitly free driver, the connector object.
	Connector/C++ takes care of freeing that.
	*/
	~MySQLBase();

	/*-----------------------------------------
	int OpenConnect(host,db,usr,pass)
	if any parameter is null;return -1;
	if connection is error ;return -2;
	if connection is normal; return 0;
	-----------------------------------------*/
	int OpenConnect(char *host, char *db, char *user, char *pass);
	int RowsCount();
};
#endif