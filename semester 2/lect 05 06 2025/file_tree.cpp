#include<iostream>
#include<string>
#include"file_tree.h"
#include<sstream>
using namespace std;

void show_tree_node(node* n, int level){
    for (int i=0;i<n->content.size();i++){
        for (int t=0;t<level;t++){
            cout<<'\t';
        }
        cout<<n->content[i]->name<<'\n';
        show_tree_node(n->content[i],level+1);
    }
}


void show_tree(file_system& fs){
    auto curr=fs.root;
    cout<<curr->name<<'\n';
    int level=1;
    for (int i=0;i<curr->content.size();i++){
        for (int t=0;t<level;t++){
            cout<<'\t';
        }
        cout<<curr->name<<'\n';
    }
}


void add(file_system fs, string fullname){
    stringstream ss(fullname);
    string part;
    auto curr=fs.root;
    while (getline(ss,part,'\\')){
        bool existst=false;
        for (int i=0;i<curr->content.size();i++){
            if (part==curr->content[i]->name){
                existst=true;
                curr=curr->content[i];
                break;
            }
        }
        if (!existst){
            node* n=new node(part);
            curr->content.push_back(n);
            curr=n;
        }

    }
}


void drop_tree(node* n){
    for (int i=0;i<n->content.size();i++){
        drop_tree(n->content[i]);
    }
    n->content.clear();
    if (n->name!="\\"){
        delete n;
        n=nullptr;
    }
}