#pragma once 
#include <iostream>
#include "tree.h"
#include"readFile.h"
#include<string>
#include<fstream>
using namespace std;

bool readFileToTree(string name_file, tree& a);
bool readFileToTreeNotBalance(string name_file, tree& a);