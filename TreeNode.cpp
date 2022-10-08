#include "BinarySearchTree.h"
void Database_BST::preorder(Database_BST_Node* node,int num){//preorder function
     if(node==NULL)
    return;

    if(node->num==num){
        Select_node = node;
        return;
    }
        preorder(node->left,num);//go to node->left
        preorder( node->right,num);//go to node->right
}
Result Database_BST::select_bst(Database_BST* bst_list, int num){//select bst
    if(root!=NULL){
        preorder(root,num); //go to preorder function
       if(Select_node == NULL){//if select node = NULL
        return SelectError;
       }
       else //if get address
        return Success;
    }
    else
        return SelectError;;
}
Database_BST_Node* Database_BST::getroot(){//get root function
    return root;//return root address
}
void Database_BST::delete_treenode(){//if bst node > 300 delete smallest node
    Database_BST_Node* currNode = root;
    while(1){
        if(currNode->right!=NULL && currNode->left==NULL){//if currNode->right != NULL go to currNode->right
            currNode = currNode->right;
        }
        if(currNode->right==NULL&& currNode->left==NULL)//if right is NULL break;
        {
            delete currNode;
            break;
        }
        currNode=currNode->left;
        //go to left 
    }
}
Result Database_BST::print_bst(Database_BST* bst_list){//print bst
   
    if(root!=NULL){
        inorder(root);//go to inorder function
        return Success;
    }
    else if(root==NULL){//if root is NULL return PrintError
        return PrintError;
    }
}
void Database_BST::inorder(Database_BST_Node* root){//inorder function
    if(root!=NULL){
        inorder(root->left);//load inorder function parameter is root->left
        fout.open("log.txt",ios::app);
        fout<<root->dir<<" / \""<<root->name<<"\" / "<<root->num<<endl;
        fout.close();
        inorder(root->right);//load inorder function parameter is root->right
    }
}
Result Database_BST::make_BST(string name, string filename,int num){//make bst function
    Database_BST_Node* currNode = root;
    Database_BST_Node* up=NULL;
    Database_BST_Node* newNode = new Database_BST_Node;
    newNode->dir=filename;
    newNode->name=name;
    newNode->num=num;
    if(root==NULL){//if root is NULL
        root=newNode;
        return(Success);//return success
    }
    else{
        while(1){
            if(currNode->num > num){//if currNode->num > num
            //go to left
                if(currNode->left==NULL){//if left is NULL
                    currNode->left=newNode;//currNode->left is newNode
                    return Success;
                }
                up=currNode;
                currNode=currNode->left;
            }
            else if(currNode->num==num){//if same unique number
                return Success;//return
            }
            else if(currNode->num < num){//if currNode->num < num
            //go to right
                if(currNode->right==NULL){//if currNode->right is NULL
                    currNode->right=newNode;//currNode->right is newNode;
                    return Success;
                }
                up=currNode;
                currNode=currNode->right;
            }
        }
    }
}