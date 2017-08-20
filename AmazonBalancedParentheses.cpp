#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(char exp[]){
	stack<char> s;
	char ch;
	int flag=0;
	for(int i=0;exp[i]!='\0';i++){
		if(exp[i]=='{' || exp[i]=='('||exp[i]=='[' ){
			s.push(exp[i]);
		}
		else {
			if(s.empty()){
				return false;
			}
			else{
				ch=s.top();
				s.pop();
				if(ch=='{' && exp[i]=='}'){
					flag=1;
				}
				else if(ch=='[' && exp[i]==']'){
					flag=1;
				}
				else if(ch=='(' && exp[i]==')'){
					flag=1;					
				}
				else{
					flag=0;
					break;
				}
			}
		}
	}
	if(s.empty() && flag) return true;
	else return false;
}

int main(){
char exp[]="{()}[]";
if(isBalanced(exp)){
	cout<<"\nBalanced Parentheses";
}
else {
	cout<<"\nNot Balanced Parentheses";
}
cout<<"\n";
system("pause");
return 0;
}

