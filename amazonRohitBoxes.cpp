#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;
/*
ALL TESTCASES PASSED
Time Taken-20 MInutes

Complexity(worst case)-->O(N)
*/

int main(){
    long long N,X,S,diff=0,min_Size=0,i,ans=0;
    vector<long long> v;
    v.clear();
    vector<long long>::iterator it;
    long long *p;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>X;
        v.push_back(X);
    }
    cin>>S;
    //To get maximum of all values in O(1) time
    long long max_Size_Box=*(max_element(v.begin(),v.end()));
    //IF no Box can accomodate the size of the item
    if(max_Size_Box<S){
        cout<<"-1";
    }
    else{                                           //provides the optimum size Box for the item
            i=0;
            for(it=v.begin();it!=v.end();it++){
                if(S<=*it){
                    diff=*it-S;
                    if(i==0){
                        min_Size=diff;
                        ans=*it;
                        i++;
                    }
                    else if(min_Size>diff){
                        min_Size=diff;
                        ans=*it;
                    }
                }
            }
        cout<<ans;
    }
    //system("pause");
    return 0;
}
