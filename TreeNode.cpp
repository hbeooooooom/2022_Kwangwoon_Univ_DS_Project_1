#include "BinarySearchTree.h"

void Database_BST::preorder(Database_BST_Node* node,int num){
     if(node==NULL)
    return;

    if(node->num==num){
        Select_node = node;
        return;
    }
        preorder(node->left,num);
        preorder( node->right,num);
}
Result Database_BST::select_bst(Database_BST* bst_list, int num){
    if(root!=NULL){
        preorder(root,num); 
       if(Select_node == NULL){
        return SelectError;
       }
       else Success;
    }
    else
        return SelectError;;
}
Database_BST_Node* Database_BST::getroot(){
    return root;
}
void Database_BST::delete_treenode(){
    Database_BST_Node* currNode = root;
    Database_BST_Node* upNode=NULL;
    while(1){
        if(currNode->left==NULL)
        {
            break;
        }
        upNode=currNode;
        currNode=currNode->left;
    }
    
    if(currNode->right==NULL)
    {
        delete currNode;
        return;
    }
    else if(currNode->right!=NULL)
    {
        upNode->left=currNode->right;
        delete currNode;
        return;
    }
}

Result Database_BST::print_bst(Database_BST* bst_list){    
    if(root!=NULL){
        cout<<"========PRINT===================="<<endl;
        inorder(root);
        return Success;
    }
    else if(root==NULL){
        return PrintError;
    }
}
void Database_BST::inorder(Database_BST_Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->dir<<" / \""<<root->name<<"\" / "<<root->num<<endl;
        inorder(root->right);
    }
}
Result Database_BST::make_BST(string name, string filename,int num){
    Database_BST_Node* currNode = root;
    Database_BST_Node* up=NULL;
    Database_BST_Node* newNode = new Database_BST_Node;

    newNode->dir=filename;
    newNode->name=name;
    newNode->num=num;
    if(root==NULL){
        root=newNode;
       
        return(Success);
    }
    else{
        while(1){
            if(currNode->num > num){
                if(currNode->left==NULL){
                    currNode->left=newNode;
                   
                    return Success;
                }
                up=currNode;
                currNode=currNode->left;
            }
            else if(currNode->num==num){
                return Success;
            }
            else if(currNode->num < num){
                if(currNode->right==NULL){
                    currNode->right=newNode;
          
                    return Success;
                }
                up=currNode;
                currNode=currNode->right;
            }
        }
    }
}