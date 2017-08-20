#include<bits/stdc++.h>

using namespace std;

int main(){
//int A[]={-4,1,1,4,2,1};
int nums[]={3,2,7,10};

int with = nums[1];
        int without = 0;
        for (int i = 2; i < 4; i++) {
            int newWith = without + nums[i];
            without = with;
            with = max(with, newWith);
        }

        int with1 = nums[4 - 2];
        int without1 = 0;
        for (int i = 4 - 3; i >= 0; i--) {
            int newWith1 = without1 + nums[i];
            without1 = with1;
            with1 = max(with1, newWith1);
        }
cout<<max(with, with1)<<endl;
return 0;
}
