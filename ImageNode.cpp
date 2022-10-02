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
   
    if(head==NULL){
        head=newNode;
        return;
    }
    
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
void Loaded_List::printnode(){
    Loaded_List_Node* currNode=head;
    Loaded_List_Node* temp=head;
    while(1){
        cout<<currNode->num<<endl;
        currNode=currNode->next;
        if(currNode==NULL){
            if(temp->down==NULL)
            break;
            currNode=temp->down;
            temp=temp->down;
        }
    }
    
}
/*void Loaded_List::make_first_node(string filename){
    Loaded_List_Node* currNode=head;
    Loaded_List_Node* newNode= new Loaded_List_Node;

    newNode->filename = filename;
    if(head==NULL){
        head=newNode;
    }
    else if(head->down==NULL){
        head->down=newNode;
        newNode->up=head;
    }
    while(1){
        if(currNode->down==NULL){break;}
        currNode=currNode->down;
    }
    currNode->down=newNode;
    newNode->up=currNode;
    return;
}

bool Loaded_List::add_chek_up(){
    Loaded_List_Node* currNode=head;
    if(currNode->up==NULL){
        return false;
    }
    else
    return true;
}*/
void Loaded_List::add_list(string name, string dir, string num){
    Loaded_List_Node* currNode = head;
    Loaded_List_Node* newNode = new Loaded_List_Node;

    newNode->filename=dir;
    newNode->name = name;
    newNode->num = num;
    if(currNode->down==NULL){//첫번째 노드 삭제하고 테스트
        currNode->down=newNode;
        newNode->up=currNode;
        return;
    }

    currNode=currNode->down;

    if(currNode->filename==dir){
        if(currNode->next==NULL){
            currNode->next=newNode;
            newNode->prev = currNode;
            return; 
        }
        while(1){
            currNode=currNode->next;
            if(currNode->next==NULL)
            break;
        }
        currNode->next=newNode;
        newNode->prev=currNode;
        return;
    }

    while(1){
        currNode=currNode->down;
        if(currNode->filename==dir)
        break;
    }

    if(currNode->next==NULL)
    {
        currNode->next=newNode;
        newNode->prev = currNode;
        return; 
    }

    while(1){
        currNode=currNode->next;
        if(currNode->next==NULL){
            break;
        }
    }
        currNode->next=newNode;
        newNode->prev = currNode;
        return;


}