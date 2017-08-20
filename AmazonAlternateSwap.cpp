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

void swap(Node **src,Node **dest){
	Node *temp1=*src;
	*src=temp1->next;
	temp1->next=*dest;
	*dest=temp1;
}

void display(Node *head){
	while(head!=NULL){
		cout<<"-->"<<head->info;
		//cout<<"-->"<<head1->info;
		head=(head)->next;
		//head1=head1->next;
	}
	
}

void alternateSwap(Node *head){
	Node *temp=head,*a=NULL,*b=NULL;
	Node **frontref,**backref;
	while(temp!=NULL){
		swap(&temp,&a);
		if(temp!=NULL){
			swap(&temp,&b);
		}
	}
	*frontref=a;
	*backref=b;
	//return *frontref; 
	display(*frontref,*backref);
}


int main(){
start=NULL;
create(1);	
create(2);
create(3);
create(4);
create(5);
create(6);
cout<<endl;
cout<<"After Swap"<<endl;
alternateSwap(start);	
cout<<"\n";
display(start);
//display(&f,*backref);
system("pause");
return 0;
}

