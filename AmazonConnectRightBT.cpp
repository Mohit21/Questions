#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int info;
    Node *left,*right;
    Node *nextR;
};

Node* insert(int n){
     Node *temp=new Node;
     temp->left=NULL;
     temp->right=NULL;
     temp->nextR=NULL;
     temp->info=n;
 return temp;
}


void connectR(Node *root){
    queue<Node *>  q;
    Node *a,*b;
    int count;
    q.push(root);
    while(1){
            int count=q.size();
            if(count==0){
                break;
            }
                while(count>0){
                    a=q.front();
                    q.pop();
                    if(q.size()>0){
                        b=q.front();
                    }
                    else{
                        b=NULL;
                    }
                    if(b!=NULL){
                        a->nextR=b;
                    }
                    else{
                        a->nextR=NULL;
                    }
                    if(a->left){
                        q.push(a->left);
                    }
                    if(a->right){
                        q.push(a->right);
                    }
                    count--;
            }
    }
}
/*
void connectR(Node *root){
if(!root){              //root!=NULL
        return;
}
if(root->left){
    root->left->nextR=root->right;
}
if(root->right){
    //root->right->nextR exists only when root->nextR exists
    root->right->nextR=(root->nextR!=NULL)?(root->nextR->left):NULL;
}
connectR(root->left);
connectR(root->right);
}

void connect(Node *root){
    root->nextR=NULL;
    connectR(root);
}
*/

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

int main(){
    Node *root=insert(20);
    root->left=insert(10);
    root->right=insert(30);
    root->left->left=insert(5);
    root->left->right=insert(15);
    root->right->left=insert(250);
    levelOrder(root);
    cout<<endl;
    connectR(root);
    cout<<"\n If connected O/p will the node data else -1"<<endl;
    cout<<"1. ";
    if(root->nextR){
        cout<<root->nextR->info;
    }
    else{
        cout<<-1;
    }
    cout<<endl;
    cout<<"2.  ";
    if(root->left->nextR){
        cout<<root->left->nextR->info;
    }
    else{
        cout<<-1;
    }
    cout<<endl;
    cout<<"3.  ";
    if(root->left->right->nextR!=NULL){
        cout<<root->left->right->nextR->info;
    }
    else{
        cout<<-1;
    }
return 0;
}
