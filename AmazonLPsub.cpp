#include<bits/stdc++.h>

using namespace std;

void lPSub(string str){
    int N=str.size(),low=0,high=0,start=0,maxlength=1;
    for(int i=1;i<N;i++){
        //Odd Length
        low=i-1;
        high=i;
        while(low>=0 && high<N && (str[low]==str[high])){
            if(maxlength<(high-low+1)){
                start=low;
                maxlength=high-low+1;
            }
            --low;
            ++high;
        }
        //even Length
        low=i-1;
        high=i+1;
        while(low>=0 && high<N && (str[low]==str[high])){
            if(maxlength<(high-low+1)){
                start=low;
                maxlength=high-low+1;
            }
            --low;
            ++high;
        }
    }
    string str1;
        for(int i=start;i<start+maxlength;i++){
            str1.push_back(str[i]);
        }
        cout<<"-->"<<str1<<endl;
    cout<<endl;
}
int main(){
string str;
//mohittihom forgeeksskeegfor
cin>>str;
lPSub(str);
return 0;
}
