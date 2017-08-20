#include<bits/stdc++.h>
using namespace std;
struct Node{
int info;
Node *next;
}*start;

Node* createN(int x){
    Node* temp=new Node;
    temp->info=x;
    temp->next=NULL;
    return temp;
}

void removeL(Node *loopnode,Node* head){
    Node *ptr1,*ptr2;
    ptr1=head;
    while(1){
        ptr2=loopnode;
        while(ptr2->next!=loopnode && ptr2->next!=ptr1){
            ptr2=ptr2->next;
        }
        if(ptr2->next==ptr1){
            break;
        }
        else{
            ptr1=ptr1->next;
        }
    }
ptr2->next=NULL;
}

bool detect(Node *head){
if(head==NULL){
    return 0;
}
Node *slow=head,*fast=head;
while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        removeL(slow,head);
        return 1;
    }
}
return 0;
}

void display(Node *head){
    while(head!=NULL){
        cout<<head->info<<"-->";
        head=head->next;
    }
}

int main(){
start=NULL;
start=createN(1);
start->next=createN(2);
start->next->next=createN(3);
start->next->next->next=createN(4);
start->next->next->next->next=createN(5);
start->next->next->next->next->next=start->next->next;

if(detect(start)){
        cout<<"YES\n";
        display(start);
}
else{
        cout<<"NO\n";
        display(start);
}
return 0;
}
