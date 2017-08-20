#include<bits/stdc++.h>
using namespace std;

int main(){
int A[]={1, 2, 2, 2, 2, 4, 5, 2, 6, 2, 8, 2, 2, 4, 2, 1, 9, 2};//
int N=sizeof(A)/sizeof(A[0]),i;
int count=0,maxcount=0,num;
for(i=0;i<N;i++){
    count=0;
    for(int j=0;j<N;j++){
        if(A[i]==A[j]){
            count++;
        }
    }
    if(maxcount<count){
        num=A[i];
        maxcount=count;
    }
}
if(maxcount>(N/2)){
        cout<<"\nNumber: "<<num<<endl;
        cout<<"\ncount: "<<count;
}
else{
    cout<<"No Majority element!";
}
return 0;
}
