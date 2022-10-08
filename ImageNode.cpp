#include"Imagelist.h"
#include<iostream>
using namespace std;
Loaded_List_Node* Loaded_List::return_head(){
    return head;//return head address
}
string Loaded_List::get_name(){
    Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL) //if the node is bottom node
        break;
        currNode=currNode->down;//go to down
    }
    
    while(1){
        if(currNode->next==NULL){//if the node is last node
            break;
        }
        currNode=currNode->next;//go to next
    }
    return currNode->name;//return name;
}
bool Loaded_List::head_check(){
    if(head->next==NULL){
        if(head->down==NULL){
            return false;//if head == NULL return false
        }
    }
    return true;//Not NULL
}
string Loaded_List::get_filename(){//
    Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)//if the node is bottom node
        break;
        currNode=currNode->down;//go to down
    }
    
    while(1){
        if(currNode->next==NULL){//if the node is last node
            break;
        }
        currNode=currNode->next;//go to next
    }
    return currNode->filename;//return filename
}
void Loaded_List::delete_head(){
    head=NULL;//retrun NULL
}
int Loaded_List::get_num(){
     Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)//if the node is bottom node
        break;
        currNode=currNode->down;//go to down
    }
    
    while(1){
        if(currNode->next==NULL){//if the node is last node
            break;
        }
        currNode=currNode->next;//go to next
    }
    return currNode->num;   //return num
}
void Loaded_List::delete_node(){
    Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)//if currNode->down break loop
        break;
        currNode=currNode->down;//go to down
    }
    
    while(1){
        if(currNode->next==NULL){//if node next is NULL break loop
            break;
        }
        currNode=currNode->next;//go to next
    }
    if(currNode->prev==NULL){//if node prev is NULL
        if(currNode->up==NULL){//and up is NULL
            head=NULL;//head is NULL
            head->next=NULL;//and next pointer is NULL
            return;//return
        }
        currNode->up->down=NULL;
    }
    else
        currNode->prev->next=NULL;
    delete currNode;
}
Result Loaded_List::modify_list(string name,string filename,int num){
   Loaded_List_Node* currNode=head;
   Loaded_List_Node* temp;
   Loaded_List_Node* newNode = new Loaded_List_Node;
    newNode->name=name;
    newNode->num=num;
    newNode->filename=filename;
    while(1){//check filename node
        if(currNode->filename==filename)
            break;
        currNode=currNode->down;//go to down if same dir name break loop
        if(currNode==NULL)//not same dir
            return ModifyError;//return error
    }
    while(1){
        if(currNode->name==name){//if name same break loop
            break;
        }
        currNode = currNode->next;//go to next
        if(currNode==NULL)//if same name is not return error
            return ModifyError;
    }
    if(currNode->next!=NULL){
        
        newNode->next = currNode->next;
        currNode->next->prev=newNode;
    }
    temp=currNode;
    currNode = currNode->prev;
    currNode->next=newNode;
    newNode->prev=currNode;

    delete temp;//delete an existing node
    return Success;

}
void Loaded_List::make_list(string name, string filename,int num){
    
    Loaded_List_Node* currNode=head;
    Loaded_List_Node* newNode = new Loaded_List_Node;
    
    newNode->name=name;
    newNode->num=num;
    newNode->filename=filename;
    
    if(head==NULL){
        head=newNode;//first data input
        return;
    }
    
    if(head->next==NULL){//second data input
        head->next=newNode;
        newNode->prev=currNode;
        return;
    }
    while(1)
    {
    if(currNode->next==NULL){break;}//end node break loop
         currNode=currNode->next;//go to next
    }
    
    currNode->next=newNode;
    newNode->prev=currNode;
    return;
}

Result Loaded_List::add_list(string name, string dir, int num){
    Loaded_List_Node* currNode = head;
    Loaded_List_Node* newNode = new Loaded_List_Node;
    newNode->filename=dir;
    newNode->name = name;
    newNode->num = num;
    if(head==NULL){
        return AddError;
    }
    if(head->filename==newNode->filename){
        if(head->next==NULL){
            head->next=newNode;
            newNode->prev=head;
            return Success;
        }
        else{
            while(1){
                if(currNode->next==NULL)
                    break;
                currNode=currNode->next;
            }
            currNode->next=newNode;
            newNode->prev=currNode;
            return Success;
        }
    }
    while(1){
        if(currNode->filename==dir){
            break;
        }
        if(currNode->down==NULL){
            currNode->down=newNode;
            newNode->up=currNode;
            return Success;
        }
        currNode=currNode->down;
    }
        if(currNode->next==NULL){
            currNode->next=newNode;
            newNode->prev = currNode;
            return Success; 
        }
        while(1){
            if(currNode->next==NULL)
            break;
            currNode=currNode->next; 
        }
        currNode->next=newNode;
        newNode->prev=currNode;
        return Success;

}
void Loaded_List::pop_head(){
    Loaded_List_Node* currNode=head;
    Loaded_List_Node* temp;
    if(head->next==NULL){
        temp=currNode;
        head=head->down;
        delete temp;
        return;
    }
    else
    {
        temp=currNode->down;
        head = currNode->next;
        head->down=temp;
        temp->up=head;
        delete currNode;
        return;
   }
    
}