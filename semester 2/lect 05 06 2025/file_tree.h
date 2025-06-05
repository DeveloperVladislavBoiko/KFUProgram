#pragma onse 
#include<string>
#include<vector>

using namespace std;


struct node{
    string name;
    vector<node*> content;
    node(string name){
        this->name=name;
    }
};


struct file_system{
    node* root=new node("\\");
};

void add(file_system fs, string fullname);
void show_tree(file_system& fs);