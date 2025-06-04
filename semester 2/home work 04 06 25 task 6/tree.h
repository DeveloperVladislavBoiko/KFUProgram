#include <queue>
#include<string>
using namespace std;

enum bypass_type{ prefix, infix, postfix, wide };

#pragma once
struct node {
    double bal;
    string name;
    string familia;
    int count = 1;
    int level = 0;
    node* left = nullptr;  // указатель на левое поддерево
    node* right = nullptr; // указатель на правое поддерево
};

struct tree {
    node* root = nullptr; // указатель на корень дерева
    int height = 0; // высота дерева
    int count = 0;  // число элементов
};

bool add_to_tree(tree& t, double value, string name, string familia);
node* find_in_tree(tree& t, double value);
bool remove_from_tree(tree& t, double value);
void drop_tree(tree& t);
queue<node*> bypass(tree t, bypass_type type = prefix);