#include<bits/stdc++.h>
using namespace std;
struct Node{
int info;
Node *left,*right;
}*root;

Node *createN(int val){
    Node *temp=new Node;
    temp->left=temp->right=NULL;
    temp->info=val;
    return temp;
}

Node* mirror(Node *root){
    if(root==NULL){
        return NULL;
    }
      Node* temp=new Node;
      temp->info=root->info;
      temp->left=mirror(root->right);
      temp->right=mirror(root->left);
    return temp;

}

void levelOrder(Node *root){
    queue<Node *>  q;
    int count;
    q.push(root);
    while(1){
            int count=q.size();
            if(count==0){
                break;
            }
                while(count>0){
                    Node *temp=q.front();
                    q.pop();
                    cout<<"-->"<<temp->info;
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                    count--;
            }
        cout<<endl;
    }
}


int main(){
root=NULL;
root=createN(5);
root->left=createN(3);
root->right=createN(2);
root->left->right=createN(1);
root->left->left=createN(7);
root->right->left=createN(8);
root->right->right=createN(10);
Node *root1=mirror(root);
cout<<"Original Tree"<<endl;
levelOrder(root);
cout<<"\nMirror Tree"<<endl;
levelOrder(root1);
return 0;
}
