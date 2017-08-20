#include<bits/stdc++.h>
using namespace std;
struct Node{
int info;
Node *left,*right;
}*root;

Node *createN(int val){
Node *t=new Node;
t->info=val;
t->left=t->right=NULL;
return t;
}

int height(Node *root){
    if(!root){
        return 0;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    return (max(lh,rh)+1);
}

int diameter(Node *root){
    if(!root){
        return -1;
    }
    int lh,rh,ld,rd;
    lh=height(root->left);
    rh=height(root->right);
    ld=diameter(root->left);
    rd=diameter(root->right);
    return max((lh+rh+1),max(ld,rd));
}

int main(){
root=NULL;

root=createN(15);
root->left=createN(10);
root->left->right=createN(11);
root->left->right->right=createN(12);
root->left->left=createN(6);
root->left->left->right=createN(8);
root->left->left->right->left=createN(7);
root->left->left->left=createN(5);
root->left->left->left->left=createN(4);
root->left->left->left->left->left=createN(3);
root->left->left->left->left->left->left=createN(2);
root->left->left->left->left->left->left->left=createN(1);
root->right=createN(20);
root->right->right=createN(21);
root->right->right->right=createN(22);
root->right->right->right->right=createN(23);
root->right->right->right->right->right=createN(24);
root->right->right->right->right->right->right=createN(25);
cout<<diameter(root);
return 0;
}
