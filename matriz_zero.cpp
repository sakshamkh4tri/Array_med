// brute force

// #include<bits/stdc++.h>
// using namespace std;
// void markrow( vector<vector<int>>&arr, int i,int m){       // setting row as zero
//     for(int k=0; k<m; k++){
//         if(arr[i][k]!=0){
//             arr[i][k]=-1;
//         }
//     }
// }
// void markcolumn( vector<vector<int>>&arr, int j,int p){           // setting column as zero
//     for(int k=0; k<p; k++){
//         if(arr[k][j]!=0){
//             arr[k][j]=-1;
//         }
//     }
// }
// void setmatrixzero(vector<vector<int>>&arr, int m, int p){
//     int n= arr.size();
//     for(int i=0; i<m; i++){                 // checking every element if it is zero then set row and col as zero
//         for(int j=0; j<p; j++){
//             if(arr[i][j]==0){
//                 markrow(arr,i,p);
//                 markcolumn(arr,j,m);
//             }
//         }
//     }
//     for(int i=0; i<m; i++){                  // for converting all -1 to 0
//         for(int j=0; j<p; j++){
//             if(arr[i][j]==-1){
//                 arr[i][j]=0;
//             }
//         }
//     }
//     for(int i=0; i<m; i++){               // for printing final setmatrixzero matrix
//         for(int j=0; j<p; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     vector<vector<int>>arr={
//         {1,1,1,1},
//         {1,0,0,1},
//         {1,0,1,1},
//         {1,1,1,1},
// };

//     setmatrixzero(arr,4,4);
// return 0;
// }

// beter solution

// #include<bits/stdc++.h>
// using namespace std;
// void setmatrixzero(vector<vector<int>>&matrix, int m, int n){
//     int p=matrix.size();
//     int rows[m]={0};            // creating two empty array as every element marked 0
//     int column[n]={0};
//     for(int i=0; i<m; i++){              // iterating through whole mat if an element is zero mark correspond row and col
//         for(int j=0; j<n; j++){
//             if(matrix[i][j]==0){
//                 rows[i]=1;
//                 column[j]=1;
//             }
//         }
//     }
//     for(int i=0; i<m; i++){                      // whose column and row is marked assign every element as 0 of them
//         for(int j=0; j<n; j++){
//             if(rows[i]==1 || column[j]==1){
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     for(int i=0; i<m; i++){                          // printing the final matrix
//         for(int j=0; j<n; j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
// vector<vector<int>>matrix={
//     {1,1,1,1},
//     {1,0,1,1},
//     {1,1,0,1},
//     {1,0,0,1},
// };

// setmatrixzero(matrix,4,4);
// return 0;
// }

// optimal solution

#include<bits/stdc++.h>
using namespace std;
void setmatrixzero(vector<vector<int>>&matrix, int m, int n){
    int p=matrix.size();
    int col0=1;
    for(int i=0; i<m; i++){        //setting first row and column instead of using extra space
        for(int j=0; j<n; j++){
            if(matrix[i][j]==0){     // if an element is zero 
                matrix[i][0]=0;           // updating  column 
                if(j!=0){                  // updating row
                    matrix[0][j]=0;
                }
                else col0=0;
            }
        }
    }
    for(int i=1; i<m; i++){              // whosoever row and column is marked assign every element as zero but only considering 3X3 mat
        for(int j=1; j<n; j++){
            if(matrix[0][j]==0 || matrix[j][0]==0){
                matrix[i][j]=0;
            }
        }
    }
    for(int i=n; i>=0; i--){          // converting marked element from first row as zero
        if(i==0){
            if(col0==0 || matrix[0][0]==0){
                col0=0;
            }
        }
        else if(matrix[0][i]==0 || matrix[0][0]==0){
            matrix[0][i]=0;
        }
    }
    for(int i=0; i<m; i++){        // conerting marked element from first col as zero
        if(matrix[i][0]==0 || col0==0){
            matrix[i][0]=0;
        }
    }
    for(int i=0; i<m; i++){               // printing final matrix
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
vector<vector<int>>matrix={
    {1,1,1,1},
    {1,0,1,1},
    {1,1,0,1},
    {1,0,0,1},
};

setmatrixzero(matrix,4,4);
return 0;
}