//  better solution

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> sorting_one_two_zero(vector<int>&arr){
//     int n = arr.size();
//     int cnt0= 0;
//     int cnt2=0;
//     int cnt1= 0;
//     for(int i=0; i<n; i++){
//         if(arr[i]==0){
//             cnt0++;
//         }
//         if(arr[i]==1){
//             cnt1++;
//         }
//         if(arr[i]==2){
//             cnt2++;
//         }
//     }

//     for(int i=0; i<cnt0; i++){
//         arr[i]=0;
//     }
//     for(int i=0; i<cnt1; i++){
//         arr[i+cnt0]=1;
//     }
//     for(int i=0; i<cnt2; i++){
//         arr[cnt0+cnt1+i]=2;
//     }
//     return arr;
// }
// int main()
// {
// vector<int>arr={0,1,2,0,1,2,1,2,0,0,0,1};
// vector<int>result=sorting_one_two_zero(arr);
// for(auto it : result){
//     cout<<it<<" ";
// }
// return 0;
// }

// optimal solution (dutch national flag algo)
#include<bits/stdc++.h>
using namespace std;
vector<int> sorting_one_zero_two(vector<int>&arr){
    int n =arr.size();
    int mid=0;
    int high=n-1;
    int low=0;
    for(int i=0; i<n; i++){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}
int main()
{
vector<int>arr={0,1,2,0,1,2,1,2,0,0,0,1};
vector<int>result=sorting_one_zero_two(arr);
for(auto it : result){
    cout<<it<<" ";
}
return 0;
}
