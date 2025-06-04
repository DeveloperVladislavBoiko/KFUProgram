#include <iostream>
#include "tree.h"
#include<fstream>

using namespace std;


bool load_tree_from_file(tree& t, string filename) {
    ifstream file;
    file.open(filename);
    if (!file){
        return false;
    }
    
    bool flag=true;
    double bal;
    std::string initials, familia;
    while (file >> bal >> initials >> familia) {
        flag=false;
        add_to_tree(t, bal, initials, familia);
    }
    file.close();
    if (flag){
        return false;
    }

    return true;
}