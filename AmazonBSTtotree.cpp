#include<iostream>
#include<queue>
#include<map>
#include<limits>
#include<vector>

using namespace std;

struct Node {
    int info;
    Node *left,*right;
};

Node* insert(int n){
     Node *temp=NULL;
     temp=new Node;
     temp->left=temp->right=NULL;
     temp->info=n;
    return temp;
}

void treetolist(Node *root,Node **head){
    if(!root){
        return;
    }
    static Node *prev=NULL;
    treetolist(root->left,head);
    if(prev==NULL){
        *head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
treetolist(root->right,head);
}

void display(Node *head){
    while(head){
        cout<<"-->"<<head->info;
        head=head->right;
    }
}

void levelOrder(Node *root){
    if(!root){
        return;
    }
    queue<Node*> q;
    q.push(root);
    int nodecount=0;
    while(1){
        nodecount=q.size();
        if(nodecount==0){
            break;
        }
        while(nodecount--){
                Node *t=q.front();
                q.pop();
                cout<<t->info<<" ";
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                        q.push(t->right);
                }
        }
        cout<<endl;
    }
}

int main(){
    Node *root;
    root=insert(20);
    root->left=insert(8);
    root->right=insert(22);
    root->left->left=insert(5);
    root->left->right=insert(3);
    root->right->left=insert(4);
    root->right->right=insert(25);
    root->left->right->left=insert(10);
    root->left->right->right=insert(14);
    levelOrder(root);
    cout<<endl;
    cout<<"Tree to List"<<endl;
    Node *head;
    treetolist(root,&head);
    display(head);
return 0;
}
