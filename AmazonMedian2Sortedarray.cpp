#include<bits/stdc++.h>

using namespace std;

int median(int A1[],int A2[],int N){
    int m1=-1,m2=-1,i=0,j=0;
    for(int k=0;k<=N;k++){
        if(A1[i]<A2[j]){
            m1=m2;
            m2=A1[i++];
        }
        else if(A1[i]>A2[j]){
            m1=m2;
            m2=A2[j++];
        }
        else if(i==N){
            m1=m2;
            m2=A2[0];
            break;
        }
        else if(j==N){
            m1=m2;
            m2=A1[0];
            break;
        }
    }
return (m1+m2)/2;
}

int main(){
int A1[]={1, 12 , 15, 26, 38},A2[]={2, 13, 17, 30, 45},N;
N=sizeof(A1)/sizeof(A1[0]);
cout<<"-->"<<median(A1,A2,N);
return 0;
}
