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
      return output_num > count_num ? true : false;
   }
   
};
#endif