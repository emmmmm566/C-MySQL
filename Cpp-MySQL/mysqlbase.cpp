#include "mysqlbase.h"

MySQLBase::MySQLBase(){
	m_myConn = NULL;
	driver = NULL;
	m_preStatement = NULL;
	m_res = NULL;
}

MySQLBase::~MySQLBase(){
	if (m_myConn != NULL){
		delete m_myConn;
	}
	if (m_preStatement != NULL){
		delete m_preStatement;
	}
	if (m_res != NULL){
		delete m_res;
	}
}
Connection * MySQLBase::GetConn(){
	return m_myConn;
}
PreparedStatement * MySQLBase::GetPreStatement(){
	return m_preStatement;
}
Statement * MySQLBase::GetStatement(){
	return m_statement;
}
ResultSet * MySQLBase::GetRes(){
	return  m_res;
}
void MySQLBase::SetRes(ResultSet * item){
	m_res = item;
}
/*-----------------------------------------
int OpenConnect(host,db,usr,pass)
if any parameter is null;return -1;
if connection is error ;return -2;
if connection is normal; return 0;
-----------------------------------------*/
int MySQLBase::OpenConnect(char *host, char *db, char *user, char *pass){
	if (NULL == host || NULL == db || NULL == user || NULL == pass) return(-1);

	driver = get_driver_instance();

	char conn[256];

	sprintf(conn, "tcp://%s:3306", host);

	m_myConn = driver->connect(conn, user, pass);

	if (!m_myConn->isValid()){
		return -2;
	}

	m_myConn->setSchema(db);

	return 0;
}
/*-----------------------------------------
int Commit(int mode)
mode 0 is CMT_START,
mode 1 is CMT_COMMIT,
mode 2 is CMT_ROLLBACK
-----------------------------------------*/
int MySQLBase::Commit(int mode){

	if (mode<CMT_START || mode>CMT_ROLLBACK){
		return -1;
	}
	if (!m_myConn->isValid()){
		return -2;
	}
	bool ret;
	switch (mode){
	case CMT_START:
		/*--------------------------------------
		While using preparedStatement,it catches an
		error,which says
		'This command is not supported in the prepared statement protocol yet
		(MySQL error code: 1295, SQLState: HY000 )'
		---------------------------------------*/
		m_statement = m_myConn->createStatement();

		ret = m_statement->execute("start transaction");

		break;
	case CMT_COMMIT:
		/*--------------------------------------
		You can also use m_myConn->commit();or rollback(),
		there is no return value in commit(),rollback();
		and  if execute("start transaction"),commit,rollback,
		it always return false;
		---------------------------------------*/
		m_statement = m_myConn->createStatement();

		ret = m_statement->execute("commit");

		break;

	case CMT_ROLLBACK:

		m_statement = m_myConn->createStatement();

		ret = m_statement->execute("rollback");

		break;

	default:
		return -1;
	}
	return 0;

}
int MySQLBase::RowsCount(){
	return m_res->rowsCount();
}