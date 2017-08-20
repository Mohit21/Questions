#include<bits/stdc++.h>

using namespace std;

struct node{
    int info;
    node *next;
}*start;

void create(int n){
    node *temp;
    if(start==NULL){
        start=new node;
        start->info=n;
        start->next=NULL;
        temp=start;
    }
    else{
        temp->next=new node;
        temp=temp->next;
        temp->info=n;
        temp->next=NULL;
    }
}

bool ispalin1(node **left,node *right){
    if(right==NULL){
        return true;
    }
    bool isp=ispalin1(left,right->next);
    if(isp==false){
        return false;
    }
    bool isp1=((*left)->info==right->info);
    (*left)=(*left)->next;
    return isp1;
}

bool isPalindrome(node *head){
    if(ispalin1(&head,head)){
        return true;
    }
    else return false;
}

int main(){
start=NULL;
create(1);
create(2);
create(2);
create(2);
create(1);
create(2);
if(isPalindrome(start)){
    cout<<"A Palindrome";
}
else{
    cout<<"Not a Palindrome";
}
return 0;
}
