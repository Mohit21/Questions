#include<iostream>
#include<queue>
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
            while(nodecount>0){
                Node *t=q.front();
                q.pop();
                cout<<t->info<<"-->";
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                        q.push(t->right);
                }
                nodecount--;
            }
            cout<<endl;
        }
}
int sum=0;
int maxSum(Node *root,Node **maxr,int maxs){
    if(!root){
        return -1;
    }
    maxSum(root->left,maxr,maxs);
    sum=sum+root->info;
    maxSum(root->right,maxr,maxs);
    if(maxs<sum){
        maxs=sum;
        *maxr=root;
    }
    return maxs;
}

int main(){
    Node *root=insert(20);
    root->left=insert(10);
    root->right=insert(30);
    root->left->left=insert(5);
    root->left->right=insert(15);
    root->right->left=insert(250);
    cout<<"LevelOrder0"<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<maxSum(root,&root,0);
    return 0;
}
