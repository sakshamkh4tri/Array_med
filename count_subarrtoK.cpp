//brute force o(n^2)

// #include<bits/stdc++.h>
// using namespace std;
// int noofsubarr(vector<int>&arr, int k){
//     int n= arr.size();
//     int count =0;
//     for(int i=0; i<n; i++){
//         int sum=0;
//         for(int j=i; j<n; j++){
//             sum+=arr[j];
//             if(sum==k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// int main()
// {
// vector<int>arr={1,2,3,-3,1,1,1,4,2,-3};
// cout<<noofsubarr(arr,3);
// return 0;
// }


// optimal solution

#include<bits/stdc++.h>
using namespace std;
int countsubarr(vector<int>&arr, int k){
    int prefixsum=0;
    int count=0;
    int n= arr.size();
    unordered_map<int,int>mpp;
    mpp[0]=1;
    for(int i=0; i<n; i++){
        prefixsum+=arr[i];
        int rem = prefixsum-k;
        count+=mpp[rem];          // we have to add  the occurance of the prefixsum
        mpp[prefixsum]++;         // updating map as same as we update  in hash table 
    }
    return count;
}
int main()
{
vector<int>arr={1,2,3,-3,1,1,1,4,2,-3};
cout<<countsubarr(arr,3);
return 0;
}