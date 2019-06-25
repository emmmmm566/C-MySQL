#ifndef TString_H
#define TString_H


#include <memory>
#include <string>
#include<iostream>
using namespace std;
class TString{
private:
	void copy_data(const char *s);
public:
	char * m_data;
	size_t m_len;
	TString();
	TString(const char * p);
	TString(TString &&str);
	TString(string &&str);
	TString & operator =(TString &&str);
	virtual ~TString(){
		if (m_data)
			delete[]m_data;
	}
};
#endif