#include "Blank.h"
int Blank::Select(){
	TString sql = "select * from blank";

	PreparedStatement * p = GetPreStatement();

	ResultSet * res = GetRes();

	GetConn()->createStatement()->execute("set names gbk");

	p = GetConn()->prepareStatement(sql.m_data);

	res = p->executeQuery();

	SetRes(res);

	MoveNext();

	Attach();

	return 0;

}
int Blank::Insert(){
	int count = 0;

	return count;

}
int Blank::Update(){
	return 0;

}
int Blank::Delete(){
	return 0;
}
void Blank::Attach(){
	
	ResultSet * res = m_res;
	id = res->getInt("id");
	question = res->getString("question").c_str();
	answer = res->getString("answer").c_str();
	type = res->getInt("type");
}
void Blank::MoveNext(void){
	GetRes()->next();
	Attach();
}
void Blank::MovePre(void){
	GetRes()->previous();
	Attach();
}

void Blank::SetQuestion(char * item){
	question = item;
}
void Blank::SetId(int item){
	id = item;
}
void Blank::SetAnswer(char * item){
	answer = item;
}
void Blank::SetType(int item){
	type = item;
}
char * Blank::GetQuestion(){
	for (int i = 0; i < question.m_len; i++){
		if (question.m_data[i] == 32){
			question.m_data[i] = '_';
		}
	}
	return question.m_data;
}
int Blank::GetId(){
	return id;
}
char * Blank::GetAnswer(){

	return answer.m_data;
}
int Blank::GetType(){
	return type;
}