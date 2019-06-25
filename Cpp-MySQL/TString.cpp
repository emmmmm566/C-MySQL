#include "TString.h"
void TString::copy_data(const char *s){
	m_data = new char[m_len + 1];
	memcpy(m_data, s, m_len);
	m_data[m_len] = '\0';
}
TString::TString(){
	m_data = NULL;
	m_len = 0;
}
TString::TString(const char * p){
	m_len = strlen(p);
	copy_data(p);
}
TString::TString(TString &&str){
	m_len = str.m_len;
	m_data = str.m_data;
	str.m_len = 0;
	str.m_data = NULL;
}
TString::TString(string &&str){
	m_len = strlen(str.data());
	m_data = (char*)str.c_str();
}
TString& TString::operator =(TString &&str){
	if (this != &str){
		m_len = str.m_len;
		m_data = str.m_data;
		str.m_len = 0;
		str.m_data = NULL;
	}
	return *this;
}