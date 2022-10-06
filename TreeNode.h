#pragma once
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

class Database_BST_Node
{
    public:
    string name;
    string dir;
    int num;
    Database_BST_Node * left=NULL;
    Database_BST_Node * right=NULL;
};