#ifndef Blank_H
#define Blank_H
#include "mysqlbase.h"
#include "TString.h"
class Blank :public MySQLBase{
private:
	int id;
	TString question;
	TString answer;
	int type;
public:
	void SetId(int);
	void SetQuestion(char *);
	void SetAnswer(char *);
	void SetType(int);
	int GetId();
	char * GetQuestion();
	char * GetAnswer();
	int GetType();


	int Select(void);
	int Update(void);
	int Delete(void);
	int Insert(void);
	void Attach(void);
	void MoveNext(void);
	void MovePre(void);

};
#endif