#include<iostream>
#include<vector>
#define mod1 503

using namespace std;

vector<string> Hash[20];

int hash(string str){
    int n=0;
    for(int i=0;i<str.size();i++){
        n+=str[i];
    }
    n%=mod1;
   return (n);
}


void insert(string str){
    int n=hash(str);
    if(n<10) Hash[n].push_back(str);
}

bool search(string s){
    int n=hash(s);
    for(int i=0;i<Hash[n].size();i++){
        cout<<Hash[n][i]<<endl;
        if(Hash[n][i]==s){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    //{"Mohit","Rohit","Rohan","Arjun"};
    string str;
    for(int i=0;i<5;i++){
            cin>>str;
            insert(str);
    }
    //Abhinav Arjuna Mohit Rohit
    if(search("Mohit")==true){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
return 0;
}
