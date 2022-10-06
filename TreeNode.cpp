#include"BinarySearchTree.h"


void Database_BST::delete_treenode(){
    Database_BST_Node* currNode = root;
    Database_BST_Node* upNode;
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
    Result result;
    
    if(root!=NULL){
        cout<<"========PRINT===================="<<endl;
        inorder(root);
        return Success;
    }
    else if(root==NULL){
        return PrintError;
    }
}

Result Database_BST::inorder(Database_BST_Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->dir<<" / \""<<root->name<<"\" / "<<root->num<<endl;
        inorder(root->right);
    }
}
Result Database_BST::make_BST(string name, string filename,string num){
    Database_BST_Node* currNode = root;
    Database_BST_Node* up;
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