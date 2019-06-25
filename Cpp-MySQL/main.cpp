#include <iostream>
#include "mysqlbase.h"
#include "Singleton.h"
using namespace std;
int main(){
	Singleton<Literature>::Instance();
	//NEVER use root user,this just for demo; 
	Dao->m_blank.OpenConnect("localhost", "literature", "root", "root");
	Dao->m_blank.Select();
	cout << Dao->m_blank.GetType() << endl;
	cout << Dao->m_blank.GetQuestion() << endl;
	cout << Dao->m_blank.GetAnswer()<< endl;
	int a;
	cin >> a;
}