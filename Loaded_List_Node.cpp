#include<iostream>
#include<cstring>

#include "Loaded_List_Node.h"
using namespace std;

void Loaded_List::read_csv_file()
{
    int num;
    char Name[100];
    fout.open(RESULT_LOG_PATH);
    string str_buf1,str_buf2;
    fstream fread;

    fread.open("./img_files/filesnumbers.csv",ios::in);

    while(!fread.eof()){
        getline(fread, str_buf1, ',');
        getline(fread, str_buf2,',');
        
        num=atoi(str_buf1.c_str());
        strcpy(Name,str_buf2.c_str());
        fout<<Name<<"/"<<num<<endl;
        make_list(Name,num);
    }
    fread.close();
    cout<<"==================="<<endl;
}

void Loaded_List::make_list(char* Name, int num){
    Loaded_List_Node* currNode = head;
    Loaded_List_Node* newNode = new Loaded_List_Node;
    newNode->num=num;
    strcpy(newNode->name,Name);

    if(head==NULL){
        head=newNode;
        return;
    }
    if(head->next==NULL){
        currNode->next=newNode;
        newNode->prev=currNode;
        return;
    }
    while(1){
        if(currNode->next==NULL)
        break;
        currNode=currNode->next;
    }
    currNode->next=newNode;
    newNode->prev=currNode;
}