#ifndef QUEUE_H
#define QUEUE_H
#include"ImageNode.h"
#include"Result.h"
#ifndef NULL
#define NULL    0
#endif

class Loaded_List{
    private:
     Loaded_List_Node* head;
    

     public:
 
    void make_list(string name, string filename, string num);//make linked list
    Result add_list(string name, string filename, string num);
    Result modify_list(string name,string filename,string num);
    bool head_check();
    void pop_head();
    void delete_head();
    string get_name();
    string get_filename();
    string get_num();
    void delete_node();
    void printnode();
};
#endif