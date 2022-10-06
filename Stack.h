#ifndef STACK_H
#define STACK_H
#include"TreeNode.h"
#include "Result.h"

#ifndef NULL
#define NULL    0
#endif

template <class T>
class Stack
{
private:
   int count_num = 0;//count list number
   T *list = new T[300]; 
public:
   Stack(){}
   ~Stack(){delete list;}

   T Pop(){
      if(count_num==-1){return NULL;}
      return list[count_num--];
   }

   void Push(T& Node){
      list[count_num] = Node;
      count_num++;
   }

   bool Isempty(){
      return count_num < 0 ? true : false;
   }
};
#endif