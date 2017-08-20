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

int length(Node *temp){
    int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
}

bool pallindrome(Node *head){
    int len=length(head);
    bool flag=false;
    Node *temp=head,*temp1;
    for(int i=1;i<len;i++){
            temp1=head;
        for(int j=0;j<=len-i-1;j++){
                temp1=temp1->next;
        }
        if(temp->info==temp1->info){
            flag=true;
        }
        else{
            flag=false;
            break;
        }
        temp=temp->next;
    }
    if(flag==true){
        return true;
    }
    else
        return false;
}
int main(){
start=NULL;
create(1);
create(2);
create(2);
create(2);
create(2);
create(1);
create(8);
cout<<endl;
display(start);
cout<<endl;
if(pallindrome(start)){
    cout<<"\nPallindrome";
}
else{
    cout<<"\nNotPallindrome";
}
return 0;
}
