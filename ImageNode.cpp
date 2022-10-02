#include"ImageNode.h"
#include"Queue.h"
#include<iostream>
using namespace std;
void Loaded_List::make_list(string name, string filename,string num){
    
    Loaded_List_Node* currNode=head;
    Loaded_List_Node* newNode = new Loaded_List_Node;
    
    newNode->name=name;
    newNode->num=num;
    newNode->filename=filename;
   
    /*if(head==NULL){
        head=newNode;
        return;
    }*/
    
    if(head->next==NULL){
        head->next=newNode;
        newNode->prev=currNode;
        return;
    }
    while(1)
    {
    if(currNode->next==NULL){break;}
    
         currNode=currNode->next;
    }
    
    currNode->next=newNode;
    newNode->prev=currNode;
    return;
}

void Loaded_List::make_first_node(string filename){
    Loaded_List_Node* currNode=head;
    Loaded_List_Node* newNode= new Loaded_List_Node;

    newNode->filename = filename;
    
    head=newNode;
    return;
}