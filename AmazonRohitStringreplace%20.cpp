#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
string str;
getline(cin,str);
int i=0;
string::iterator it,it1;
for(it=str.begin();it!=str.end();it++){
    if(it!=npos){
            it=str.find(' ',it);

    }

}
cout<<str<<endl;
return 0;
}
