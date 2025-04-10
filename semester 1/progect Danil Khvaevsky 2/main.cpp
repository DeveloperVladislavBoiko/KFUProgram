#include<iostream>
#include"matrix.h"
using namespace std;
int main() {
 int n, m;
 //setlocale(LC_ALL, "");
 cout << "Введите размеры вашей матрицы через пробел" << '\n';
 cin >> n >> m;
 int** mas = nullptr;
 create_mas(mas, n, m);
 zero_mas(mas, n, m);
 int* hisla = new int[n * m];
 readNumbers(hisla, n * m * 3);
 print_mas(mas, n, m);
 delete[]hisla;
 delete_mas(mas, n, m);
 return 0;
}