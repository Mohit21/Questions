#include<bits/stdc++.h>
using namespace std;

int main(){
int i,j,ind1=-1,ind2=-1,num,N=5;
int A[][5]={{10,20,30,40,50},
            {15,25,35,45,47},
            {23,29,37,46,48},
            {27,33,39,49,52},
            {29,34,41,53,57}};
cin>>num;
i=0;
j=N-1;
while(i<N && j>-1){
    if(num==A[i][j]){
        ind1=i;
        ind2=j;
        break;
    }
    else if(num<A[i][j]){
        j--;
    }
    else if(num>=A[i][j]){
        i++;
    }
}
if(ind1==-1 && ind2==-1){
    cout<<"Not Found";
}
else{
    cout<<"Found at Index: "<<ind1+1<<" "<<ind2+1;
}
return 0;
}
