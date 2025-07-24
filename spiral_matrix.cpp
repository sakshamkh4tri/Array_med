// it has only one solution

#include<bits/stdc++.h>
using namespace std;
vector<int> spiralmatrix(vector<vector<int>>&matrix){
    int n = matrix.size();
    int left=0;
    int top=0;
    int right=5;
    int bottom=5;
    vector<int>temp;
    while(top<=bottom && left<=right){
        for(int i=left ; i<=right; i++){     // for left to right
            temp.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++){           // top to bottom
            temp.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){            // what if if a matrix only have one row so we have to print left to right only 
            for(int i= right; i>=left; i--){            // right to left
                temp.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){                         // this  condition is also for edge case 
            for(int i= bottom; i>=top; i--){             // bottom to top
                temp.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return temp;
}
int main()
{
    vector<vector<int>>arr={
        {1,2,3,4,5,6},
        {20,21,22,23,24,7},
        {19,32,33,34,25,8},
        {18,31,36,35,26,9},
        {17,30,29,28,27,10},
        {16,15,14,13,12,11},
    };
    vector<int>result=spiralmatrix(arr);
    for(auto it: result){
        cout<<it<<" ";
    }
return 0;
}