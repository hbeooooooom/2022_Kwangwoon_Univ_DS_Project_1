#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include"Result.h"
#include"Imagelist.h"
#include"Stack.h"
#include"BinarySearchTree.h"
#include<algorithm>
#include<cstdlib>
using namespace std;

class Manager
{
public:
 
    ~Manager();
    std::ifstream fread;
    std::ifstream fin;
    int nodecount = 0;
    int tree_nodecount =0;
    Result result;
    void PrintError(Result result);
    void Run(const char* filepath);
    
private:
    Result Load(const char* filepath,Loaded_List* Load_list);
    Result ADD(const char* filepath,Loaded_List* Load_list,string dir,string path);
    Result MODIFY(const char*filepath, Loaded_List* Load_list,string dir,string img_name,int num );
    Result MOVE(const char*filepath, Loaded_List* Load_list,Database_BST* BST_list,int nodecount);
    Result PRINT(Database_BST* BST_list);
    Result SEARCH(Database_BST* BST_list, string word);
    Result SELECT(Database_BST* BST_list, int num);
    Result EDIT(Database_BST* BST_list,string cmd, int num);
};