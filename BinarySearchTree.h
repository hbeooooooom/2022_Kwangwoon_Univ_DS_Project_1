#include "TreeNode.h"
#include "Result.h"
#include "Stack.h"
#include "Queue.h"
#include<fstream>
class Database_BST{ //BST class
    Database_BST_Node* root=NULL; // root address
    Database_BST_Node* Select_node;//SELECT command address into Select_node
    public:
        const char* RESULT_LOG_PATH = "log.txt";
        ofstream fout;
        Result make_BST(string name, string filename,int num); //put the data in the BST
        Result print_bst(Database_BST* bst_list);//get tree head(Inorder)
        Result select_bst(Database_BST* bst_list, int num);//get tree head(postodr)
        void inorder(Database_BST_Node* node);//inorder function
        void delete_treenode();//if more than 300 node delete node
        Database_BST_Node* getroot();//return root address
        void preorder(Database_BST_Node* node,int num);//preorder function
        Result get_picture(string cmd, int num);//picture function
        
};