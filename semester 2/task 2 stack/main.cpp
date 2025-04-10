#include <iostream>
#include <sstream>
#include <string>
#include"stack.h"
using namespace std;





int main() {
    setlocale(LC_ALL, "");
	cout<<"Введите ваше выражение оно может содержать пробелы и иные символы и скобки вида () {} [] <>"<<'\n';
	cout<<"Учтите, что скобки разных видов считаются разными, и не должно быть ситуации вида ([)]"<<'\n';
    string s;
	getline(cin,s);
	int index1, index2;
	if(search_staples(s, index1,index2)==1){
		cout<<"количество скобок и их порядок верные"<<'\n';
	}
	else if(search_staples(s, index1, index2)==-1){
		cout<<"порядок скобок не верный, ситуация вида ({)} индексы ошибочных скобок "<<index1<<' '<<index2<<'\n';
	}
	else if (search_staples(s, index1, index2)==-2){
		cout<<"встречена закрывающая скобка без открывающей с индексом "<<index1<<'\n';
	}
	else {
		cout<<"нет закрывающей скобки индекс не закрытой скобки "<<index1<<'\n';
	}
    return 0; 
}
