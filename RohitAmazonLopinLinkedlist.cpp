#include<bits/stdc++.h>
using namespace std;
struct Node{
int info;
Node *next;
}*start;

Node *createN(int val){
    Node *temp=new Node;
    temp->info=val;
    temp->next=NULL;
    return temp;
}


void removeLoop(Node *loopnode,Node *head){
Node *ptr1=head,*ptr2=NULL;
while(1){
    ptr2=loopnode;
    while(ptr2->next!=loopnode && ptr2->next!=ptr1){
        ptr2=ptr2->next;
    }
    if(ptr2->next=ptr1){
        break;
    }
    else{
        ptr1=ptr2->next;
    }
}
ptr2->next=NULL;
}

bool detectLoop(Node *head){
    if(head==NULL){
            return false;
        }
    else{
        Node *slow,*fast;
        slow=head;
        fast=head;
        while(slow && fast &&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                removeLoop(slow,head);
                return true;
            }
        }
    return false;
    }
}


void display(Node *head){
    cout<<"After Loop removal"<<endl;
    while(head){
        cout<<head->info<<"  ";
        head=head->next;
    }
cout<<endl;
}

int main(){
start=NULL;
start=createN(1);
start->next=createN(2);
start->next->next=createN(3);
start->next->next->next=createN(4);
start->next->next->next->next=createN(5);
start->next->next->next->next->next=createN(6);
start->next->next->next->next->next->next=start->next->next->next;
if(detectLoop(start)){
    cout<<"Loop exists"<<endl;
}
else{
    cout<<"No Loop"<<endl;
}
display(start);
return 0;
}

