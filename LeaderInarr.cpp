//brute force

// #include<bits/stdc++.h>
// using namespace std;
// vector<int>leaderinarray(vector<int>&arr){
//     int n=arr.size();
//     vector<int>temp;
//     int count=0;
//     for(int i=0; i<n-1; i++){          // check for every number
//         int num=arr[i];
//         for(int j=i; j<n-1; j++){         // every number after that must be smaller
//             if(num>arr[j+1]){
//                 count+=1;
//             }
//             else if(num<arr[j+1]) break;
//         }
//         if(count==(n-i-1)){
//             temp.push_back(num);
//         }
//             count=0;
//     }
//     temp.push_back(arr[n-1]);       // put the last element bcoz it is always greater
//     return temp;
// }
// int main()
// {
// vector<int>arr={10,22,12,3,0,6};
// vector<int>result=leaderinarray(arr);
// for(auto it : result){
//     cout<<it<<" ";
// }

// return 0;
// }


//optimal solution

#include<bits/stdc++.h>
using namespace std;
vector<int>leaderofarray(vector<int>&arr){
    vector<int>temp;
    int n=arr.size();
    int mini=-1;
    for(int i=0; i<n-1; i++){
        int num =arr[i];
        mini=max(arr[i+1],arr[n-1]);
        if(num>mini){
            temp.push_back(num);
        }
    }
    temp.push_back(arr[n-1]);
    return temp;
}
int main()
{
vector<int>arr={10,22,12,3,0,6};
vector<int>result=leaderofarray(arr);
for(auto it : result){
    cout<<it<<" ";
}
return 0;
}