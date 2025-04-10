#include <iostream>
#include <ctime>
#include"matrix.h"
using namespace std;

void create_mas(int**& mas, int n, int m) {
    mas = new int* [n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[m];
    }
}

void delete_mas(int**& mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        delete[] mas[i];
    }
    delete[]mas;
    mas = nullptr;
}


void zero_mas(int** mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mas[i][j] = 0;
        }
    }
}

void print_mas(int** mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mas[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


