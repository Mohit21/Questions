#include<iostream>
using namespace std;

int countSpaces(string s1){
    int sp=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==' '){
                sp++;
        }
    }
    return sp;
}

string getReverse(string str){
int len=str.size(),space,j=0,prev;
if(len==0){
    return str;
}
else{
    space=countSpaces(str);
    if(space==0){
        return str;
    }
    else{
        string out=" ";
        out.resize(len);
        for(int i=len-1;i>=0;i--){
            if(str[i]==' '){
                --space;
                if(j==0){
                    for(int k=i+1;k<len;k++){
                            out[j++]=str[k];
                    }
                    out[j++]=' ';
                    prev=i;
                }
                else{
                    for(int k=i+1;k<prev;k++){
                            out[j++]=str[k];
                    }
                    out[j++]=' ';
                    prev=i;
                }
                if(space==0){
                    for(int k=0;k<prev;k++){
                        out[j++]=str[k];
                    }
                    break;
                }
            }
        }
    return out;
    }
}
}

int main(){
string input;
getline(cin,input);
string output=getReverse(input);
cout<<output;
return 0;
}
