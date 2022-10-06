#include "TreeNode.h"
#include "Result.h"
#include "Stack.h"
#include "Queue.h"
class Database_BST{
    
    Database_BST_Node* root=NULL;
    public:
        Result make_BST(string name, string filename,int num);
        Result print_bst(Database_BST* bst_list);
        Result inorder(Database_BST_Node* node);
        void fine_delete_treenode();
        void delete_treenode();
        Database_BST_Node* getroot();
        
    
};