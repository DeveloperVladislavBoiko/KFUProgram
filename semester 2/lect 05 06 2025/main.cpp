#include<iostream>
#include<string>
#include"file_tree.h"

using namespace std;
int main (){
    setlocale(LC_ALL,"");
    file_system fs;
    add(fs,"C:\\Windows\notepad.exe");
    add(fs,"C:\\Windows\sistem32\drivers\etc\hosts");
    show_tree(fs);
    add(fs,"C:\\Windows\Program file");
    show_tree(fs);
    return 0;
}