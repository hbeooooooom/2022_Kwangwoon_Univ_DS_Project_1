#ifndef STACK_H
#define STACK_H
#include"TreeNode.h"
#include "Result.h"

#ifndef NULL
#define NULL    0
#endif

template <class T>
class Stack_Node
{
public:
    T Data;
    StackNode* next = NULL;
    StackNode* prev = NULL;
    StackNode(T data) : Data(data), next(NULL), prev(NULL) {};
};
template <class T>


class Stack
{
private:
   StackNode<T>* top;// top of stack
   StackNode<T>* bottom; // bottom of stack
public:
   Stack(): top(NULL), bottom(NULL) {};

   bool isEmpty() // if Stack is empty, return true
   {
      return bottom == nullptr ? true : false;
   };
   T Top()//                            
   {
      return bottom->Data;
   };
   void Push(T data){
      StackNode<T>* newNode = new StackNode<T>;
      newNode->Data = data;

      if (top == NULL) {
         top = newNode;
         bottom = newNode;
      }
      else {
         bottom->next = newNode;
         newNode->prev = bottom;
         bottom = bottom->next;
      }
   };
   T Pop()
   {
      if (isEmpty()) //      stack            
      {
         return NULL;
      }
      else
      {
         StackNode<T>* curr = bottom;
         T data = curr->Data;

         if (top == bottom)// Just one data in stack
         {
            bottom = nullptr;
            delete top;
            top = nullptr;
         }
         else// more than two data in stack
         {
            data = bottom->Data;
            StackNode<T>* popNode = bottom;
            bottom = bottom->prev;
            delete popNode;
         }
         return data;
      }
   }
   
};
template class Stack<Database_BST_Node>;
template class Stack<unsigned char>;
#endif