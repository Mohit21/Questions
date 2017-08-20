#include<bits/stdc++.h>
using namespace std;

string mapping(int d){
    switch(d){
        case 0:
            return "0";
        case 1:
            return "1";
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        default:
            return "";
    }
}
void combinations(vector<string> &ans,vector<string> &container,string s,int i,int j){
    int n=container.size();
    if(i==n){
        ans.push_back(s);
        cout<<"\nI am here";
        return;
    }
		s+="z";
    for(;j<container[i].size();j++){
        s[s.length()-1]=container[i][j];
        cout<<"\nI am here :"<<i<<"."; 
        combinations(ans,container,s,i+1,0);
    }


}
vector<string> letterCombinations(string A) {
    string temp="";
    vector<string> container;
    vector<string> ans;
    for(int i=0;i<A.length();i++)
        container.push_back(mapping(A[i]-'0'));
    combinations(ans,container,temp,0,0);
    return ans;
}

int main(){
	string str="23";
	vector<string> v=letterCombinations(str);
	for(int i=0;i<v.size();i++){
		cout<<"-->"<<v[i]<<endl;
	}
	return 0;
}