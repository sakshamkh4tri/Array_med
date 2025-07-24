//brute force   o(n^2)
// #include<bits/stdc++.h>
// using namespace std;
// int buyorsellstock(vector<int>&arr){
//     int n=arr.size();
//     int maxi=INT_MIN;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             int profit= arr[j]-arr[i];   // sell -buy
//             if(profit>maxi)             // if profit>maxi update maxi
//             maxi=profit;
//         }
//     }
//     if(maxi<0) return 0;                 // if the maxi is in negative it means we made a loss 
//     return maxi;
    
// }
// int main()
// {
// vector<int>arr={4,2};
// cout<<buyorsellstock(arr);

// return 0;
// }

// optimal solution
#include<bits/stdc++.h>
using namespace std;
int buyorsellstock (vector<int> &arr){
    int n=arr.size();
    int mini = arr[0];
    int profit=0;
    for(int i=1; i<n; i++){
        int check = arr[i]-mini;
        profit=max(check,profit);
        mini=min(mini,arr[i]);
    }
    return profit;
}
int main()
{
    vector<int>arr={7,1,5,3,6,4};
    cout<<buyorsellstock(arr);

return 0;
}
 