#include "TreeNode.h"
#include "Result.h"
#include "Stack.h"
#include "Queue.h"
class Database_BST{
    
    Database_BST_Node* root=NULL;
    Database_BST_Node* Select_node;//SELECT command address into Select_node
    public:
        Result make_BST(string name, string filename,int num);
        Result print_bst(Database_BST* bst_list);//get tree head(Inorder)
        Result select_bst(Database_BST* bst_list, int num);//get tree head(postodr)
        void inorder(Database_BST_Node* node);
        void fine_delete_treenode();
        void delete_treenode();
        Database_BST_Node* getroot();
        void preorder(Database_BST_Node* node,int num);
        Result get_picture(string cmd, int num);
        
    
};