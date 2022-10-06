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
   int count_num = -1;//count list number
   T *list; 
public:
    Stack() { list = new T[300]; }

   T Pop(){
      if(count_num<0){return NULL;}
      return list[count_num--];
   }

   void Push(T& Node){
      list[++count_num] = Node;
   }

   bool Isempty(){
      return count_num < 0 ? true : false;
   }
};
#endif