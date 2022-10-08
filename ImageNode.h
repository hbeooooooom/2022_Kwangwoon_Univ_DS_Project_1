#include<cstring>
#include<string>
#include <iostream>
using namespace std;

#pragma once
class Loaded_List_Node
{
public:
    int num; // files number
    string name; // files name
    string filename;//dir name
    Loaded_List_Node* next = NULL;
    Loaded_List_Node* prev = NULL;
	Loaded_List_Node* down = NULL;
	Loaded_List_Node* up = NULL;
	
};
