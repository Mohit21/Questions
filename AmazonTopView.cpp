#include<iostream>
#include<queue>
#include<map>
#include<limits>

using namespace std;

struct Node {
    int info;
    int hd;
    Node *left,*right;
};

Node* insert(int n){
     Node *temp=NULL;
     temp=new Node;
     temp->left=temp->right=NULL;
     temp->info=n;
     temp->hd=INT_MAX;
    return temp;
}

void topView(Node *root){
    if(!root){
        return;
    }
    int hd=0;
    queue<Node*> q;
    map<int,int> mp;
    map<int,int>::iterator itm;
    root->hd=hd;
    q.push(root);
    while(!q.empty()){
                Node *t=q.front();
                q.pop();
                hd=t->hd;
                if(mp.find(hd)==mp.end()){
                        mp[hd]=t->info;
                }
                if(t->left){
                    t->left->hd=hd-1;
                    q.push(t->left);
                }
                if(t->right){
                        t->right->hd=hd+1;
                        q.push(t->right);
                }
            }
    for(itm=mp.begin();itm!=mp.end();itm++){
        cout<<itm->second<<" ";
    }
}

int main(){
    Node *root;
    root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    root->left->right=insert(5);
    root->left->left=insert(4);
    root->right->left=insert(6);
    root->right->right=insert(7);
    cout<<"Top View"<<endl;
    topView(root);
return 0;
}
