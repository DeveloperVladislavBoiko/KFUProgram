#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void zamena(string name) {
	ifstream file_read;
	char ch;
	string name_file_sistem="file_sistem.txt";
	file_read.open(name);
	ofstream file_sistem_record;
	file_sistem_record.open(name_file_sistem);
	while (file_read.get(ch)) {
		file_sistem_record << ch;
	} 
	file_read.close();
	file_sistem_record.close();
	ofstream file_record;
	file_record.open(name);
	ifstream file_sistem_read;
	file_sistem_read.open(name_file_sistem);
	while (file_sistem_read.get(ch)) {
		switch (ch) {
		case '0':
			file_record << "zero";
			break;
		case '1':
			file_record << "one ";
			break;
		case '2':
			file_record << "two ";
			break;
		case '3':
			file_record << "three  ";
			break;
		case '4':
			file_record << "four ";
			break;
		case '5':
			file_record << "five ";
			break;
		case '6':
			file_record << "six ";
			break;
		case '7':
			file_record << "seven ";
			break;
		case '8':
			file_record << "eight ";
			break;
		case '9':
			file_record << "nine ";
			break;
		default:
			file_record << ch;
		}
	}
	file_sistem_read.close();
	file_record.close();
}
int main() {
	setlocale(LC_ALL, "");
	zamena("file1.txt");
	/*в задании сказано заменить каждую отдельную цифру,
	из контекста не совсем понятно менять ли все или только отделенные пробелами,
	я посчитал что нужно заменить все,
	если я не прав и требовалось второе, то это легко фикситься доп.условием на соседние элементы*/
}
