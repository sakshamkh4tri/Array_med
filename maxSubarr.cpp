//brute force   o(n^3)
// #include<bits/stdc++.h>
// using namespace std;
// int maxsubarray(vector<int>&arr){
//     int n= arr.size();
//     int maxi=INT_MIN;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum=0;
//             for(int k=i; k<=j; k++){          //subarray length will be j-i
//                 sum+=arr[k];
//                 maxi=max(sum,maxi);
//             }
//         }
//     }
//     return maxi;
// }
// int main()
// {
// vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
// cout<<maxsubarray(arr);
// return 0;
//}

//better sol      o(n^2)
// #include<bits/stdc++.h>
// using namespace std;
// int maxsubarray(vector<int>&arr){
//     int n= arr.size();
//     int maxi=INT_MIN;
//     for(int i=0; i<n; i++){
//         int sum=0;
//         for(int j=i; j<n; j++){
//             sum+=arr[j];
//             maxi=max(sum,maxi);
//         }
//     }
//     return maxi;
// }
// int main()
// {
// vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
// cout<<maxsubarray(arr);
// return 0;
// }

//optimal solution (kadane algo)
// #include<bits/stdc++.h>
// using namespace std;
// int maxsubarray(vector<int>&arr){

//     int maxi=INT_MIN;
//     int n= arr.size();
//     int sum=0;
//     for(int i=0; i<n; i++){
//         if(sum<0){
//             sum=0;
//         }
//         else if(sum>=0){
//             sum+=arr[i];
//             maxi=max(sum,maxi);
//         }
//     }
//     return maxi;
// }
// int main()
// {
    
//     vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
//     cout<<maxsubarray(arr);
    

// return 0;
// }

// what if i want to print that max subarray

#include<bits/stdc++.h>
using namespace std;
int maxsubarray(vector<int>&arr){

    int n= arr.size();
    int maxi=INT_MIN;
    int sum=0;
    int start =0;
    int ansStart=-1;
    int ansEnd=-1;
    for(int i=0; i<n; i++){
        if(sum==0) start=i;    // you will notice whenever sum==0 subarray id starting
        if(sum<0) sum=0;
        sum+=arr[i];
        maxi=max(sum,maxi);
        ansStart= start;
        ansEnd= i;
    }
    for(int i= ansStart ; i<ansEnd; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}
int main()
{
    
    vector<int>arr={-2,-3,4,-1,-2,1,5,-3};
    cout<<maxsubarray(arr);
    

return 0;
}