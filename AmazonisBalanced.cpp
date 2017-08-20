#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
int info;
Node *left,*right;
}*root;

void insert(Node **tree,int n){
	Node *temp;
	if(!*tree){
		temp=new Node;
		temp->left=temp->right=NULL;
		temp->info=n;
		*tree=temp;
		return;
	}
	if(n<=((*tree)->info)){
		insert(&((*tree)->left),n);
	}
	else if(n>((*tree)->info)){
		insert(&((*tree)->right),n);
	}

}

void inOrder(Node *tree){
	if(tree){
		inOrder(tree->left);
		cout<<"-->"<<tree->info;
		inOrder(tree->right);
	}
}

int max(int a,int b){
	if(a>b) return a;
	else return b;
}

int height(Node *tree){
	if(tree==NULL)	return 0;
	else 1+max(height(tree->left),height(tree->right));
}

bool isBalanced(Node *tree){
	if(tree==NULL){
		return true;
	}
	else{
		int lh,rh;
		lh=height(tree->left);
		rh=height(tree->right);
		if((abs(lh-rh)<2) && isBalanced(tree->left) && isBalanced(tree->right)){
			return true;
		}
		else return false;
	}
}



int main(){
root=NULL;
/**/
insert(&root,56);
insert(&root,23);		
insert(&root,78);
insert(&root,2);
insert(&root,34);
insert(&root,59);
insert(&root,57);
insert(&root,61);
insert(&root,89);
insert(&root,111);
insert(&root,123);
/*
insert(&root,45);
insert(&root,41);		
insert(&root,49);
insert(&root,39);
insert(&root,43);
insert(&root,345);
*/

cout<<endl;
//inOrder(root);
if(isBalanced(root)){
	cout<<"\nBalanced";
}
else {
	cout<<"\nNot Balanced";
}
system("pause");
return 0;
}
