// optimal solution

#include<bits/stdc++.h>
using namespace std;
vector<int> nextpermutation(vector<int>&arr){
    int n= arr.size();
    int index=-1;
    for(int i=n-2; i>=0; i--){                       // for finding breakpoint
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){                                 // edge case
            reverse(arr.begin(),arr.end());
            return arr;
        }
    for(int i=n-1; i>index; i--){                   // finding a num slightly >1 
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1,arr.end());        // reversing the leftover array 
    return arr;
}
int main()
{
vector<int>arr={2,1,5,4,3,0,0};
vector<int>result=nextpermutation(arr);
for(auto it : result){
    cout<<it<<" ";
}
return 0;
}