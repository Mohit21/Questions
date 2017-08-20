/*
count spaces and add 2*spaces(%2 and 1 is already there as space) in the old length
then traverse from behind and kep on shifting the array values
*/
#include<iostream>
#include<cstring>

using namespace std;

#define rep(i,N) for(int i=0;i<N;i++) 
#define rrep(i,N) for(int i=N-1;i>=0;i--)


char* replace(char *string){
int len=strlen(string),countS=0;
rep(i,len){
	if(string[i]==' '){
		countS++;
	}
	cout<<string[i];
}

cout<<endl<<endl;
int len1=len+(2*countS);
//last Null value to terminate the string
string[len1]='\0';
rrep(i,len){
	if(string[i]==' '){
		string[len1-1]='0';
		string[len1-2]='2';
		string[len1-3]='%';
		len1-=3;
	}
	else{
		string[len1-1]=string[i];
		len1-=1;
	}
}
	return string;
}



int main(){
char string[]="This is a test";

cout<<replace(string)<<endl;
system("pause");
return 0;
}


