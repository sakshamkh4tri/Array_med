//brute force

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> twosum(vector<int>&arr,int target){
//     int n= arr.size();
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(arr[i]+arr[j]==target){
//                 return {i,j};
//             }
//         }

//     }
//     return{0,0};
// }
// int main()
// {
// vector<int>arr={2,6,5,8,11};
// vector<int>result=twosum(arr,14);
// for(auto it : result){
//     cout<<it<<" ";
// }
// return 0;
// }

// better solution (using hashmap)

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> twosum(vector<int>&arr, int target){
//     int n=arr.size();
//     map<int,int>mpp;
//     for(int i=0; i<n; i++){
//         int a = arr[i];
//         int required= target-a;
//         if(mpp.find(required)!=mpp.end()){
//             return {i,mpp[required]}; 
//         }
//         mpp[a]=i;
//     }
//     return{0,0};
// }
// int main()
// {
// vector<int>arr={2,6,5,8,11};
// vector<int>result=twosum(arr,14);
// for(auto it : result){
//     cout<<it<<" ";
// }
// return 0;
// }

// optimal solution

#include<bits/stdc++.h>
using namespace std;
bool twosum(vector<int>&arr, int target){
    int n=arr.size();
    int j=n-1;
    int i=0;
    sort(arr.begin(),arr.end());
    while(i<j){
        if(arr[i]+arr[j]>target){
            j--;
        }
        else if(arr[i]+arr[j]<target){
            i++;
        }
        else if(arr[i]+arr[j]==target){
            return true;
        }
    }
    return false;
}
int main()
{
vector<int>arr={2,6,5,8,11};
cout<<twosum(arr,14);

return 0;
}

