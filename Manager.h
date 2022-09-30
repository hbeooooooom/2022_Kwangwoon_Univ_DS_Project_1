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
    Result Load(const char* filepath,Queue* Load_list);
public:
    ~Manager();
    std::ifstream fread;
    void PrintError(Result result);
    void Run(const char* filepath);
    
};