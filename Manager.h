#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include"Result.h"
#include"Queue.h"
using namespace std;

class Manager
{
private:
    Result Load(const char* filepath,Loaded_List* Load_list);
public:
    int nodecount = 0;
    ~Manager();
    std::ifstream fread;
    std::ifstream fin;

    void PrintError(Result result);
    void Run(const char* filepath);

};