#ifndef STACK_H
#define STACK_H
#include"TreeNode.h"
#include"string"
#include "Result.h"

#ifndef NULL
#define NULL    0
#endif

template <class T>
class Stack//SEARCH stack
{
private:
   int count_num = -1;//count list number
   T *list; 
public:
    Stack() { list = new T[300]; }//max stack size
   ~Stack(){delete[] list;}
   T Pop(){
      if(count_num<0){return NULL;}//if count num < 0 is empty
      return list[count_num--];//pop data
   }
   void Push(T& Node){
      list[++count_num] = Node;//push data
   }
   bool Isempty(){
      return count_num < 0 ? true : false;
   }
};
template<class T>
class Edit_Stack_Node{//EDIT Stack 
//linked list node
   public:
   T node;
   Edit_Stack_Node<T>* next=NULL;
   Edit_Stack_Node<T>* prev=NULL;

   
};
template<class T>
class Edit_Stack{//EDIT Stack
//linked list
   private:
   Edit_Stack_Node<T>* top=NULL;
   Edit_Stack_Node<T>* bottom = NULL;

   public:
   bool Isempty(){//check empty Stack
      return bottom != NULL ? true : false;
   }
   void Push(T node){
      Edit_Stack_Node<T>* newNode = new Edit_Stack_Node<T>;
      newNode->node=node;
      if(bottom == NULL){//if first data
         bottom = newNode;//push data into bottom,top
         top = newNode;
      }

      else{
         bottom->next = newNode;
         newNode->prev=bottom;
         bottom=bottom->next;
         //not first data
      }
   }
   T Pop(){
      if(Isempty()==false){//if Stack empty
         return NULL;
      }
      else{
         Edit_Stack_Node<T>* currNode = bottom;
         T data = currNode->node;
         if(top==bottom){
            bottom = NULL;
            delete top;
            top = NULL;
            //if last node Pop check and delete node
         }
         else{
            Edit_Stack_Node<T>* temp =currNode;
            bottom=bottom->prev;
            delete temp;
            //pop Node and delete node
         }
         return data;
      }
   }
};


#endif