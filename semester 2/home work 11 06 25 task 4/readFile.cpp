#include <iostream>
#include "tree.h"
#include<fstream>
using namespace std;

bool readFileToTree(string name_file, tree& a){
    ifstream file(name_file);
    if (file.is_open()){
        bool file_read=false;
        int read;
        while(file>>read){
            add_to_tree(a,read, true);
            file_read=true;
        }
        file.close();
        return file_read;
        
    }
    else {
        file.close();
        return false;
    }
}

bool readFileToTreeNotBalance(string name_file, tree& a){
    ifstream file(name_file);
    if (file.is_open()){
        bool file_read=false;
        int read;
        while(file>>read){
            add_to_tree(a,read, false);
            file_read=true;
        }
        file.close();
        return file_read;
        
    }
    else {
        file.close();
        return false;
    }
}