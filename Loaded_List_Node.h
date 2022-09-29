#pragma once
#include <fstream>

class Loaded_List_Node
{
public:
    int num; // files number
    char name[100]; // files name
    Loaded_List_Node * next=NULL;
    Loaded_List_Node* prev=NULL;
};

class Loaded_List
{
private:
    Loaded_List_Node* head;
    std::ofstream fout;
    const char* RESULT_LOG_PATH = "log.txt";

public:
    void read_csv_file();//read csv files
    void make_list(char *Name, int num);//make liked list
};