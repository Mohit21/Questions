#include<iostream>

using namespace std;
int countSpace(string str){
    int cs=0;
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            cs++;
        }
    }
    return cs;
}

string reverseS(string str){
int len=str.size(),j=0,prev=0,countS=0;
string s="";

if(len==0){
    return str;
}
else{
    countS=countSpace(str);
    s.resize(len);
    if(countS==0){
        return str;
    }
    else{
        for(int i=len-1;i>=0;i--){
            if(str[i]==' '){
                countS--;
                if(j==0){
                    for(int k=i+1;k<len;k++){
                            s[j++]=str[k];
                    }
                    s[j++]=' ';
                    prev=i;
                }
                else{
                    for(int k=i+1;k<prev;k++){
                        s[j++]=str[k];
                    }
                    s[j++]=' ';
                    prev=i;
                }
            }
            if(countS==0){
                for(int k=0;k<prev;k++){
                    s[j++]=str[k];
                }
                break;
            }
        }
    //cout<<s.size()<<endl;
    return s;
    }
}
}

int main(){
string input;
getline(cin,input);
//cout<<input.size()<<endl;
string out=reverseS(input);
cout<<out<<endl;
return 0;
}
