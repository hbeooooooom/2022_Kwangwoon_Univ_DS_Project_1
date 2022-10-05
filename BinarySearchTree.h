#include "TreeNode.h"
#include "Result.h"
class Database_BST{
    private:
    Database_BST_Node* root=NULL;
    public:
        Result make_BST(string name, string filename,string num);
        Result print_bst(Database_BST* bst_list);
        Result inorder(Database_BST_Node* node);
        void delete_treenode();
    
};