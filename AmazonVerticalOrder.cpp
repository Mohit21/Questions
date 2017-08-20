#include<iostream>
#include<queue>
#include<map>
#include<vector>
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

void VerticalOrder(Node *root){
    if(!root){
        return;
    }
    int hd=0;
    queue<Node*> q;
    map<int,vector<int> > mp;
    map<int,vector<int> >::iterator itm;
    root->hd=hd;
    q.push(root);
    while(!q.empty()){
                Node *t=q.front();
                q.pop();
                hd=t->hd;
                mp[hd].push_back(t->info);
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
        for(int i=0;i<itm->second.size();i++){
                cout<<itm->second[i]<<"-->";
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
    cout<<"Vertical Order"<<endl;
    VerticalOrder(root);
return 0;
}
