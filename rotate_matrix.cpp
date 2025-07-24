// brute force

// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> rotatematrix(vector<vector<int>>&matrix, int n){
//     vector<vector<int>>temp(n,vector<int>(n));  // think of a 2d vector with size n=3 where every one is a vector in itself
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             temp[j][n-i-1]=matrix[i][j];
//         }
//     }
//     return temp;
// }
// int main()
// {
// vector<vector<int>>matrix={
//     {1,2,3,4},
//     {5,6,7,8},
//     {9,10,11,12},
//     {13,14,15,16},
// };
// vector<vector<int>>result=rotatematrix(matrix,4);
// for(auto row : result){     // this traverse through the rows which in itself is a vector
//     for(auto val : row){
//         cout<<val<<" ";
//     }
//     cout<<endl;
    
// }
// return 0;
// }

// optimal solution

#include<bits/stdc++.h>
using namespace std;
void rotatematrix(vector<vector<int>>&matrix, int n){
    for(int i=0; i<n-1; i++){               // transpose of matrix
        for(int j=0; j<n-1-i; j++){
            swap(matrix[i][j+1+i],matrix[j+i+1][i]);
        }
    }
    // for(int i=0; i<=n-1; i++){        // reversing each row one by one 
    //     for(int j=0; j<n/2; j++){
    //         swap(matrix[i][j],matrix[i][n-1-j]);
    //     }
    // }

    // another way of reversing 
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());   // matrix[i] represent whole row 
    }
    
    
    for(int i=0; i<n; i++){             // printing final matrix
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>>matrix={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16},
};
rotatematrix(matrix,4);

return 0;
}