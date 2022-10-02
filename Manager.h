#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include"Result.h"
#include"Queue.h"
using namespace std;

class Manager
{
public:
 
    ~Manager();
    std::ifstream fread;
    std::ifstream fin;
    int nodecount = 0;
    
    void PrintError(Result result);
    void Run(const char* filepath);
    
private:
    Result Load(const char* filepath,Loaded_List* Load_list);
    Result ADD(const char* filepath,Loaded_List* Load_list,string dir,string path);
    void print(Loaded_List* Load_list);
};