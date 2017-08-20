#include<iostream>
using namespace std;

struct Node{
    int info;
    Node *left,*right;
}*root;

void insert(Node **tree,int n){
    Node *temp;
    if(!*tree){             //*tree==NULL
        temp=new Node;
        temp->left=temp->right=NULL;
        temp->info=n;
        *tree=temp;
        return;
    }
    if(n<=((*tree)->info)){
        insert(&((*tree)->left),n);
    }
    else{
        insert(&((*tree)->right),n);
    }
}
/*
void inorder(Node *tree){
    if(tree){
        inorder(tree->left);
        cout<<"-->"<<tree->info;
        inorder(tree->right);
    }
}*/

int min_height(Node *tree){
    if(tree==NULL){
        return 0;
    }
    else if(tree->left==NULL && tree->right==NULL){
        return 1;
    }
    else if(tree->left==NULL){
        return min_height(tree->right)+1;
    }
    else if(tree->right==NULL){
        return min_height(tree->left)+1;
    }
    return min(min_height(tree->left),min_height(tree->right))+1;
}

int max_height(Node *tree){
    int lh=0,rh=0;
    if(tree==NULL){
        return 0;
    }
    else{
        lh=max_height(tree->left);
        rh=max_height(tree->right);
    }
    if(lh>rh){
        return (lh+1);
    }
    else
        return (rh+1);
}

int main(){
    Node *root=NULL;
    insert(&root,45);
    insert(&root,41);
    insert(&root,46);
    insert(&root,39);
    insert(&root,42);
    insert(&root,47);
    insert(&root,38);
    insert(&root,40);
   // inorder(root);
    int maxH=0,minH=0;
    maxH=max_height(root);
    cout<<"\nMaxH="<<maxH<<endl;
    minH=min_height(root);
    cout<<"\nMinH="<<minH<<endl;
    if(maxH-minH>1){
        cout<<"\nUnBalanced"<<endl;
    }
    else{
        cout<<"\nBalanced"<<endl;
    }
    system("pause");
    return 0;
}
