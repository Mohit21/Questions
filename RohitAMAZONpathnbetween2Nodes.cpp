#include<bits/stdc++.h>

using namespace std;

struct Node{
int info;
Node *left,*right;
};

Node* newnode(int val){
    Node *temp=new Node;
    temp->info=val;
    temp->left=temp->right=NULL;
    return temp;
}
void getPath(Node *root,int n1,int n2){
    list<int> q;
    if(root==NULL){
        return;
    }
    else{
        Node *lt=root;
        Node *rt=root;
        //q.push(n1);
        while(n1!=lt->info && lt){
            if(lt->left){
                    lt=lt->left;
            }
            else{
                break;
            }
            q.push_back(lt->info);
        }
        while(!q.empty()){
            cout<<q.back();
            q.pop_back();
        }
        while(n2!=rt->info && rt){
            //cout<<"h2";
            q.push_back(rt->info);
            if(rt->right){
                    rt=rt->right;
            }
            else{
                break;
            }
        }
        q.push_back(n2);
        while(!q.empty()){
            cout<<q.front();
            q.pop_front();
        }
    }
}
Node* getLCA(Node *root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    else if(root->info==n1||root->info==n2){
        return root;
    }
    Node *left=getLCA(root->left,n1,n2);
    Node *right=getLCA(root->right,n1,n2);
    if(left!=NULL && right!=NULL){
        return root;
    }
    else if(left==NULL && right==NULL){
        return NULL;
    }
    return (left!=NULL?left:right);
}

int main(){
Node *root=newnode(1);
root->left=newnode(2);
root->right=newnode(3);
root->left->left=newnode(4);
root->left->right=newnode(5);
root->right->left=newnode(6);
root->right->right=newnode(7);
root->right->left->right=newnode(8);

int n1,n2;
//4 5    8 5   4 6      4 3
cin>>n1>>n2;
Node *lca=getLCA(root,n1,n2);
//cout<<endl<<lca->info<<endl;
getPath(lca,n1,n2);
return 0;
}
