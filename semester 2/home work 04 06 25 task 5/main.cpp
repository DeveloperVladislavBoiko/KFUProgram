#include <iostream>
#include "tree.h"
#include<cmath>
#include <algorithm>
#include"readFile.h"
#include <cctype>

using namespace std;

void show_tree(tree t, bypass_type type) {
    auto q = bypass(t, type);
    while (q.size() > 0) {
        auto curr = q.front();
        if (curr) {
            cout << curr->familia << " " << curr->name 
                 << " (" << curr->bal << ", level: " << curr->level << ")";
        }
        else {
            cout << "-";
        }
        cout << " ";
        q.pop();
    }
    cout << endl;
}

void show_tree(tree t, bypass_type type, char bucva) {
    bucva=toupper(bucva);
    auto q = bypass(t,prefix);
    bool flag=true;
    while (q.size() > 0) {
        auto curr = q.front();
        if (curr && ((curr->familia)[0]==bucva)) {
            cout << "Фамилия: " << curr->familia 
                << ", Имя: " << curr->name 
                << ", Балл: " << curr->bal 
                << ", Уровень в дереве: " << curr->level << '\n';
            flag=false;
        }
        q.pop();
    }
    if (flag) {
        cout << "Нет подходящих значений" << '\n';
    }
    else {
        cout << endl;    
    }
}

int main() {
    tree t;
    if (!load_tree_from_file(t, "fileSistem.txt")) {
        cout << "Ошибка открытия файла с данными. Файл не найден, либо пуст" << '\n';
        return 0;
    }
    
    char bucva;
    cout << "Введите букву для поиска: " << '\n';
    cin >> bucva;
    show_tree(t, wide, bucva);   
    drop_tree(t);
    return 0;
}