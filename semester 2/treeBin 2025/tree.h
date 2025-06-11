#include <queue>
using namespace std;

enum bypass_type{ prefix, infix, postfix, wide };

#pragma once
struct node {
	int value; // �������� ��������
	int count = 1; // ���������� ���������� ��������
	int level = 0; // ����. ������ ����������� + 1
	node* left = nullptr;  // ��������� �� ����� ���������
	node* right = nullptr; // ��������� �� ������ ���������
};

struct tree {
	node* root = nullptr; // ��������� �� ������ ������
	int height = 0; // ������ ������
	int count = 0;  // ������� �����
};

/// <summary>
/// ���������� �������� � ������
/// </summary>
/// <param name="t">������, � ������� ����� �������� ����� �������</param>
/// <param name="value">��������, ����������� � ������</param>
/// <returns>true, ���� � ������ �������� ����� ���� � false, ���� �������� �������
/// ���������� ��������� � ����� �� ������������ �����
/// </returns>
bool add_to_tree(tree& t, int value);

/// <summary>
/// ����� �������� � ������
/// </summary>
/// <param name="t">������, � ������� �������������� ����� ��������</param>
/// <param name="value">������� ��������</param>
/// <returns>��������� �� ���� ������ � ��������������� ���������, 
/// ���� ��� ������� � ������ � nullptr - � ��������� ������</returns>
node* find_in_tree(tree& t, int value );

/// <summary>
/// �������� ���� � �������� ��������� �� ������
/// </summary>
/// <param name="t">������, �� �������� ��������� ������� ��������</param>
/// <param name="value">��������� �� ������ ��������</param>
/// <returns>true, ���� �������� ���� ������� � false, ���� �������� � ������ �� ����</returns>
bool remove_from_tree(tree& t, int value);

/// <summary>
/// �������� ����� ������ �� ������
/// </summary>
/// <param name="t">������, ������� ��������� �������</param>
void drop_tree(tree& t);

/// <summary>
/// ����� ����� ������ ���������� ���������
/// </summary>
/// <param name="t">������, ������� ����� ������</param>
/// <param name="type">��� ������</param>
/// <returns>�������, ���������� ������������������ ������ ������</returns>
queue<node*> bypass(tree t, bypass_type type = prefix);
