#include<bits/stdc++.h>
using namespace std;


int start(int A[],int beg,int end1,int x,int N){
    if(end1>=beg){
        int mid=(beg+end1)/2;
        if((mid==0 || A[mid]==x) && A[mid-1]<x){
            //cout<<"h1"<<mid<<endl;
            return mid;
        }
        else if(A[mid]<x){
            //cout<<"h2";
            return start(A,(mid+1),end1,x,N);
        }
        else{
            //cout<<"h3";
            return start(A,beg,(mid-1),x,N);
        }
    }
    else{
            return -1;
    }

}

int last(int A[],int beg,int end1,int x,int N){
    if(end1>=beg){
        int mid=(beg+end1)/2;
        if((mid==N-1 || A[mid+1]>x) && A[mid]==x){
            return mid;
        }
        else if(A[mid]>x){
            return last(A,beg,(mid-1),x,N);
        }
        else{
            return last(A,(mid+1),end1,x,N);
        }
    }
    else{
            return -1;
    }

}


int occur(int A[],int N,int x){
    int stroc,endoc;
    stroc=start(A,0,N-1,x,N);
    if(stroc==-1){
        return stroc;
    }
    endoc=last(A,stroc,N-1,x,N);
    //cout<<endl<<str<<" "<<end<<endl;
    return (endoc-stroc+1);
}

int main(){
int A[]={1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 6, 6, 7, 8, 9};
int N=sizeof(A)/sizeof(A[0]);
int x;
cin>>x;
cout<<occur(A,N,x);
return 0;
}
