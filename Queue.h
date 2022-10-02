#ifndef QUEUE_H
#define QUEUE_H
#include"ImageNode.h"
#ifndef NULL
#define NULL    0
#endif

class Loaded_List{
    private:
     Loaded_List_Node* head;

     public:
  //void make_first_node(string filename);
    void make_list(string name, string filename, string num);//make linked list
    void add_list(string name, string filename, string num);
   //bool add_chek_up();
    void printnode();
};
#endif