#include<iostream>
using namespace std;
struct Node{
    int info;
    Node *next;
}*start;

void create(int n){
    Node *temp;
    if(start==NULL){
        start=new Node;
        start->info=n;
        start->next=NULL;
        temp=start;
    }
    else{
        temp->next=new Node;
        temp=temp->next;
        temp->info=n;
        temp->next=NULL;
    }
}

void display(Node *temp){
    while(temp!=NULL){
        cout<<"-->"<<temp->info;
        temp=temp->next;
    }
}


Node *reverse(Node *head){
    if(!head){
        return NULL;
    }
    else{
        Node *prev=NULL,*next1=NULL;
        while(head){
            next1=head->next;
            head->next=prev;
            prev=head;
            head=next1;
        }
        return prev;
    }
}

void move(Node **src,Node **dest){
    Node *temp=*src;
    *src=temp->next;
    temp->next=*dest;
    *dest=temp;
}

Node *merge(Node *a,Node *b){
    Node*b1=b;
    while(b->next){
        Node *t1,*t2;
        t1=a->next;
        t2=b->next;
        if(!t1){break;}
        b->next=a;
        a->next=t2;
        a=t1;
        b=t2;
    }
    if(a){
        while(a){b->next=a;b=b->next;a=a->next;}
    }
    return b1;
}
void alternateSwap(Node *head,Node ** firstref,Node **scndref){
    Node *a=NULL,*b=NULL;
    while(head!=NULL){
        move(&head,&a);
        if(head){
            move(&head,&b);
        }
    }
    *firstref=a;
    *scndref=b;
    *firstref=reverse(*firstref);
    *scndref=reverse(*scndref);
    *scndref=merge(*firstref,*scndref);
}

void display1(Node *F,Node *S){
    //S=reverse(S);
    while(S!=NULL ){
        //cout<<F->info<<"--> ";
        cout<<"-->"<<S->info;
        //F=F->next;
        S=S->next;
    }
}

int main(){
start=NULL;
create(1);
create(2);
create(3);
create(4);
create(5);
create(6);
create(7);
cout<<endl;
display(start);
cout<<"\nAfterSwap\n"<<endl;
Node *first=NULL,*second;
alternateSwap(start,&first,&second);
display1(first,second);
return 0;
}

