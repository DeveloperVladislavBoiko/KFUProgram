#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void zamena(string name1, string name2) {
	string str;
	string name_sistem_file = "file_program.txt";
	ifstream file1_read;
	file1_read.open(name1);
	ofstream file_record;
	file_record.open(name_sistem_file);
	while (getline(file1_read, str)) {
		file_record << str << '\n';
	}
	file_record.close();
	file1_read.close();
	ifstream file2_read;
	ofstream file1_record;
	file1_record.open(name1);
	file2_read.open(name2);
	while (getline(file2_read, str)) {
		file1_record << str << '\n';
	}
	file1_record.close();
	file2_read.close();
	ofstream file2_record;
	file2_record.open(name2);
	ifstream file_read;
	file_read.open(name_sistem_file);
	while (getline(file_read,str)) {
		file2_record << str << '\n';
	}
	file_read.close();
	file2_record.close();
	
}

int main() {
	zamena("file1.txt", "file2.txt");
}
