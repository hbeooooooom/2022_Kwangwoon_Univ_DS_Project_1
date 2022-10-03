#include"ImageNode.h"
#include"Queue.h"
#include<iostream>
using namespace std;

Result Loaded_List::modify_list(string name,string filename,string num){
   Loaded_List_Node* currNode=head;
   Loaded_List_Node* temp;
   Loaded_List_Node* newNode = new Loaded_List_Node;
    newNode->name=name;
    newNode->num=num;
    newNode->filename=filename;
    while(1){//check filename node
        if(currNode->filename==filename)
            break;
        
        currNode=currNode->down;

        if(currNode==NULL)
            return ModifyError;
    }
    
    while(1){
        if(currNode->name==name){
            break;
        }
        currNode = currNode->next;
        if(currNode==NULL)
            return ModifyError;
    }
    if(currNode->next!=NULL){
        
        newNode->next = currNode->next;
    }
    temp=currNode;
    currNode = currNode->prev;
    currNode->next=newNode;
    newNode->prev=currNode;

    delete temp;
    return Success;

}

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

Result Loaded_List::add_list(string name, string dir, string num){
    Loaded_List_Node* currNode = head;
    Loaded_List_Node* newNode = new Loaded_List_Node;

    newNode->filename=dir;
    newNode->name = name;
    newNode->num = num;
    if(head==NULL){
        return AddError;
    }

    if(currNode->down==NULL){//첫번째 노드 삭제하고 테스트
        currNode->down=newNode;
        newNode->up=currNode;
        return Success;
    }

    currNode=currNode->down;

    if(currNode->filename==dir){
        if(currNode->next==NULL){
            currNode->next=newNode;
            newNode->prev = currNode;
            return Success; 
        }
        while(1){
            currNode=currNode->next;
            if(currNode->next==NULL)
            break;
        }
        currNode->next=newNode;
        newNode->prev=currNode;
        return Success;
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
        return Success; 
    }

    while(1){
        currNode=currNode->next;
        if(currNode->next==NULL){
            break;
        }
    }
        currNode->next=newNode;
        newNode->prev = currNode;
        return Success;
}