#include <iostream>
#include "tree.h"
#include"readFile.h"
#include<string>
using namespace std;

void show_tree(tree t, bypass_type type) {
	auto q = bypass(t, type);
	while (q.size() > 0) {
		auto curr = q.front();
		if (curr) {
			cout << curr->value << "(" << curr->count << "; " << curr->level << ")";
		}
		else {
			cout << "-";
		}
		cout << " ";
		q.pop();
	}
	cout << endl;
}

int main() {
	tree t_balance;
	string file_name="file_tree.txt";
	if (!readFileToTree(file_name,t_balance)){
		cout<<"Ошибка открытия файла для сбалансированного дерева. Файл не найден, либо пуст"<<'\n';
		return 0;
	}
	tree t_not_balance;
	if (!readFileToTreeNotBalance(file_name,t_not_balance)){
		cout<<"Ошибка открытия файла для не сбалансированного дерева. Файл не найден, либо пуст"<<'\n';
		return 0;
	}
	cout<<"Балансированное дерево с инфиксным обходом"<<'\n';
	show_tree(t_balance, infix);
	cout<<"Не балансированное дерево с инфиксным обходом"<<'\n';
	show_tree(t_not_balance, infix);
	drop_tree(t_balance);
	drop_tree(t_not_balance);
	return 0;
}