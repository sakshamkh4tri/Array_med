//brutre force
// #include<bits/stdc++.h>
// using namespace std;
// int majorityelement(vector<int>&nums){
//     int n= nums.size();
//         unordered_map<int,int>mpp;        //created a map
//         for(int i=0;i<n; i++){            // count how much time a element appears
//             mpp[nums[i]]++;
//         }
//         for(auto it: mpp){              // checking condition and printing
//             if(it.second>n/2){
//                 return it.first;
//             }
//         }
//         return 1;
//     }
// int main()
// {
// vector<int>arr={-1,1,1,1,2,1};
// cout<<majorityelement(arr);
// return 0;
// }

//optimal solution  (moore voting algo)
#include<bits/stdc++.h>
using namespace std;
int majorityelement(vector<int>&arr){
    int count=0;
    int element =arr[0];
        if(arr.size()<=1){            // edge case if array contains only one element return that element
            return arr[0];
        }
    for(int i=0; i<arr.size(); i++){         // moore's voting algo
        if(arr[i]==element){
            count++;
        }
        else count--;

        if(count==0){
            element=arr[i+1];
            count=0;
        }
    }
        int cnt=0;
    for(int i=0; i<arr.size(); i++){            //checking how many times that element appears
        if(arr[i]==element){
            cnt++;
        }
    }
    if(cnt>arr.size()/2){
        return element;
    }

    return -1;
}
int main()
{
vector<int>arr={0,-1,-1,-1};
cout<<majorityelement(arr);
return 0;
}

