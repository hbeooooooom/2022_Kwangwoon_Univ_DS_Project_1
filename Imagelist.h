#include"ImageNode.h"
#include"Result.h"

class Loaded_List{
    private:
     Loaded_List_Node* head = NULL;
     public:
 
    void make_list(string name, string filename, int num);//make linked list
    Result add_list(string name, string filename, int num);
    Result modify_list(string name,string filename,int num);
    bool head_check();
    void pop_head();
    void delete_head();
    string get_name();
    string get_filename();
    int get_num();
    void delete_node();
    void printnode();
};
