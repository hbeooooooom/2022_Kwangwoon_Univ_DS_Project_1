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
    const char* RESULT_LOG_PATH = "log.txt";//log file
    std::fstream fout;
    std::ifstream fread;
    std::ifstream fin;
    int nodecount = 0;//node counting max size 100
    int tree_nodecount =0;//tree node counting max size 300
    Result result;
    void PrintError(Result result);//print error message
    void Run(const char* filepath);
    
private:
    Result Load(const char* filepath,Loaded_List* Load_list);//LOAD command function
    Result ADD(const char* filepath,Loaded_List* Load_list,string dir,string path);//ADD command function
    Result MODIFY(const char*filepath, Loaded_List* Load_list,string dir,string img_name,int num );//MODIFY command function
    Result MOVE(const char*filepath, Loaded_List* Load_list,Database_BST* BST_list,int nodecount);//MOVE command function
    Result PRINT(Database_BST* BST_list);//PRINT command function
    Result SEARCH(Database_BST* BST_list, string word);//SEARCH command function
    Result SELECT(Database_BST* BST_list, int num);//SELECT command function
    Result EDIT(Database_BST* BST_list,string cmd, int num);//EDIT command function
    void delete_treememory(Database_BST_Node* node);//EXIT command function
    void delete_listmemory(Loaded_List_Node * node);//EXIT command function

};