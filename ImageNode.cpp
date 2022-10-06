#include"Imagelist.h"
#include<iostream>
using namespace std;

string Loaded_List::get_name(){
    Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)
        break;
        currNode=currNode->down;
    }
    
    while(1){
        if(currNode->next==NULL){
            break;
        }
        currNode=currNode->next;
    }
    return currNode->name;
}
bool Loaded_List::head_check(){
    if(head->next==NULL){
        if(head->down==NULL){
            return false;
        }
    }
    return true;
}
string Loaded_List::get_filename(){//head is already end node
    Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)
        break;
        currNode=currNode->down;
    }
    
    while(1){
        if(currNode->next==NULL){
            break;
        }
        currNode=currNode->next;
    }
    return currNode->filename;
}
void Loaded_List::delete_head(){
    head=NULL;
}
int Loaded_List::get_num(){
     Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)
        break;
        currNode=currNode->down;
    }
    
    while(1){
        if(currNode->next==NULL){
            break;
        }
        currNode=currNode->next;
    }
    return currNode->num;   
}

void Loaded_List::delete_node(){
    Loaded_List_Node* currNode=head;
    while(1){
        if(currNode->down==NULL)
        break;
        currNode=currNode->down;
    }
    
    while(1){
        if(currNode->next==NULL){
            break;
        }
        currNode=currNode->next;
    }
    if(currNode->prev==NULL){
        if(currNode->up==NULL){
            head=NULL;
            head->next=NULL;
            return;
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
        currNode->next->prev=newNode;
    }
    temp=currNode;
    currNode = currNode->prev;
    currNode->next=newNode;
    newNode->prev=currNode;

    delete temp;
    return Success;

}

void Loaded_List::make_list(string name, string filename,int num){
    
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
        if(currNode==NULL){
            if(temp->down==NULL){
            break;
            }
            currNode=temp->down;
            temp=temp->down;
        }
        cout<<currNode->filename<<" "<<currNode->name<<"/"<<currNode->num<<endl;
        currNode=currNode->next;
    }
    
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
    
    return AddError;
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