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

void printLmost(Node *tree,int level,int *l){
	if(tree==NULL){
		return;
	}
	if(*l<level){
		cout<<"-->"<<tree->info<<endl;
		*l=level;
	}
	printLmost(tree->left,level+1,l);
	printLmost(tree->right,level+1,l);
}

int main(){
root=NULL;
/**/
insert(&root,5);
insert(&root,4);
insert(&root,7);
insert(&root,6);
insert(&root,3);
cout<<endl;
int l=0;
printLmost(root,1,&l);
system("pause");
return 0;
}
