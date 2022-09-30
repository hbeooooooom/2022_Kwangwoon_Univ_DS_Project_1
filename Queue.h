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
     void make_list(string name, string filename, string num);//make liked list
};
#endif