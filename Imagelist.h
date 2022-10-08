#include"ImageNode.h"
#include"Result.h"

class Loaded_List{ // linked list function
    private:
     Loaded_List_Node* head = NULL; //head address
     public:
 
    void make_list(string name, string filename, int num);//make linked list
    Result add_list(string name, string filename, int num);//add linked list
    Result modify_list(string name,string filename,int num);//modify function
    bool head_check();//check if there is head function
    void pop_head();//if node>100 delete first in node function
    void delete_head();//return NULL function
    string get_name();//return img name function
    string get_filename();//return file name function
    int get_num();//return number function
    void delete_node();//bst node >300 delete smallest node function
    void printnode();//command load make list after print load list function
    Loaded_List_Node*  return_head();//return head address function
};
