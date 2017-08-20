#include<bits/stdc++.h>
using namespace std;

int bSearchE(vector<int> A,int beg,int end,int X,int N){
    if(beg<end){
        int mid=(beg+end)/2;
        cout<<endl<<A[mid]<<" "<<mid;

        if((mid==N-1 || A[mid+1]>=X) && A[mid]==X){
            return mid;
        }
        else if(A[mid]>X){
            return bSearchE(A,beg,mid-1,X,N);
        }
        else{
            return bSearchE(A,mid+1,end,X,N);
        }
    }
    return -1;
}


int bSearchS(vector<int> A,int beg,int end,int X,int N){
    if(end>=beg){
        int mid=(beg+end)/2;
        cout<<endl<<A[mid]<<" "<<mid;

        if((mid==0 || A[mid-1]<=X) && A[mid]==X){
            return mid;
        }
        else if(A[mid]>X){
            return bSearchS(A,beg,mid-1,X,N);
        }
        else{
            return bSearchS(A,mid+1,end,X,N);
        }
    }
    return -1;
}

int findCount(const vector<int> &A, int B) {
    int beg=0,end=0;
    beg=bSearchS(A,0,A.size()-1,B,A.size());
    cout<<endl<<beg<<endl;
    if(beg==-1){
        return 0;
    }
    end=bSearchE(A,beg,A.size()-1,B,A.size());
    return (end-beg+1);
}

int main(){
vector<int> A;
int n;
for(int i=0;i<34;i++){
    cin>>n;
    A.push_back(n);
}
int B=1;
cout<<findCount(A,B)<<endl;
return 0;
}
