#include<iostream>
#include<fstream>
using namespace std;
#define ll long long int
int main(){
    ofstream outfile;
    outfile.open("large.txt");
    string s="",s1="",s2="";
    for(ll i=0;i<1000;i++){
        s+='+';
    }
    for(ll i=0;i<500;i++){
        s1+='-';
    }
    for(ll i=0;i<=50;i++){
        s2+='+';
    }
    int K1=20,K=500,K2=2,j=0;
    for(ll i=0;i<1000;i++){
        if(j%3==0){
            outfile<<s<<" "<<K<<endl;
        }
        else if(j%3==1){
            outfile<<s1<<" "<<K1<<endl;
        }
        else{
            outfile<<s2<<" "<<K2<<endl;
        }
        j++;
    }
    outfile.close();
return 0;
}
