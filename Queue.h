#ifndef QUEUE_H
#define QUEUE_H
#include"TreeNode.h"
#include "Result.h"

#ifndef NULL
#define NULL    0
#endif
template <class Q>
class Queue
{
private:
   int count_num = 0;
   int output_num = 0;
   Q * list = new Q[300];
public:
   ~Queue(){
      delete list;
   }
   Q Pop(){
      if(output_num >count_num){return NULL;}
      return list[output_num++];
   }

   void Push(Q& Node){
      list[count_num]= Node;
      count_num++;
      return;
   }

   bool Isempty(){
      return output_num >= count_num ? true : false;
   }
   
};
template <class Q2>
class Queue2
{
   private:
   int size=NULL;
   int count_num = 0;
   int output_num = 0;
   int count_num=-1;
   T2* Node;
public:
   Stack2(){};
   Stack2(int a, int b){
      Node = new T2[a*b];
      size=a*b;
      }
   void Push(T2& Node11){
      Node[++count_num] = Node11;
   }
   T2 Pop(){
      if(count_num<0){return 0;}
      return Node[count_num--];
   }
   bool Isempty(){
      return count_num < 0 ? true : false;
   }
};
#endif