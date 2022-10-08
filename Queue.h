#ifndef QUEUE_H
#define QUEUE_H
#include"TreeNode.h"
#include "Result.h"

#ifndef NULL
#define NULL    0
#endif
template <class Q>
class Queue//search queue
{
private:
   int count_num = 0;
   int output_num = 0;
   Q * list = new Q[300];//bst max size 300
public:
   ~Queue(){
      delete[] list;
   }
   Q Pop(){
      if(output_num >count_num){return NULL;}//if queue is empty
      return list[output_num++];//return queue
   }

   void Push(Q& Node){
      list[count_num]= Node;//push list into node
      count_num++;//count node++
      return;
   }

   bool Isempty(){
      return output_num >= count_num ? true : false;//output num same count num is empty
   }
   
};
template <class Q>
class Img_Queue_node{//EDIT queue node
   public:
   Img_Queue_node<Q>* next = NULL;
   Img_Queue_node<Q>* prev = NULL;
   Q data;  
};
template<class Q>
class IMG_Queue{//EDIT queue list
   private:
   Img_Queue_node<Q>* head=NULL;
   Img_Queue_node<Q>* tail=NULL;
   
   public:
   bool Isempty(){
      return head->next != NULL ? true : false;//queue empty check
   }
   void Push(Q node){
      Img_Queue_node<Q>* newNode = new Img_Queue_node<Q>;
      newNode->data=node;

      if(head==NULL){
         head = newNode;
         tail = newNode;
      }
      else if(tail!=NULL){//push data
         tail->next=newNode;//data into tail next
         tail = tail->next;//and tail is newNode
      }
   }
   Q Pop(){
      if(Isempty()==false){//if queue is empty
         return NULL;
      }
      else{
         Q data = head->data;
         if(head==tail){//if empty queue delete memory
            head = NULL;
            delete tail;
            tail = NULL;
         }
         
         if(data >=255){//if RGB >255 max RGB is 255
            data=255;
         }
         Img_Queue_node<Q>* temp=head;
         head = head->next;
         delete temp;//delete pop node
         return data;//return data
      }
      
   }

};
#endif