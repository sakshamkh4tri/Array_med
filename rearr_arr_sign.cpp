//brute force        t.c o(2n)     s.c o(n)
// #include<bits/stdc++.h>
// using namespace std;
// vector<int>rearrangearray(vector<int>&arr){
//     vector<int>positive;
//     vector<int>negative;
//     int n= arr.size();
//     for(int i=0; i<n; i++){        // positive contains all +ve elements in order  and negative will have -ve element
//         if(arr[i]>=0){
//             positive.push_back(arr[i]);
//         }
//         else negative.push_back(arr[i]);
//     }
//    for(int i=0; i<n/2; i++){
//         arr[2*i]=positive[i];
//    }
//    for(int i=0; i<n/2; i++){
//         arr[2*i+1]=negative[i];
//    }
//     return arr;
// }
// int main()
// {
// vector<int>arr={3,1,-2,-5,2,-4};
// vector<int>result=rearrangearray(arr);
// for(auto it : result){
//     cout<<it<<" ";
// }
// return 0;
// }

// optimal solution
// #include<bits/stdc++.h>
// using namespace std;
// vector<int>rearrangearray(vector<int>&arr){
//     int n= arr.size();
//     vector<int>temp(n,0);
//     int positive=0;
//     int negative=1;
//     for(int i=0; i<n; i++){
//         if(arr[i]>0){
//             temp[positive]=arr[i];
//             positive+=2;
//         }
//         else {
//             temp[negative]=arr[i];
//             negative+=2;
//         }
//     }
//     return temp;
// }
// int main()
// {
//     vector<int>arr={3,1,-2,-5,2,-4};
//     vector<int>result=rearrangearray(arr);
//     for(auto it : result){
//     cout<<it<<" ";
// }

// return 0;
// }

//variety 2 if the number of +ve and -ve are not equal and we have to arrange alternative +ve -ve and whichever element left should be added to the last

 #include<bits/stdc++.h>
using namespace std;
vector<int>rearrangearray(vector<int>&arr){
    vector<int>positive;
    vector<int>negative;
    int n= arr.size();
    for(int i=0; i<n; i++){        // positive contains all +ve elements in order  and negative will have -ve element
        if(arr[i]>=0){
            positive.push_back(arr[i]);
        }
        else negative.push_back(arr[i]);
    }
    int pos = positive.size();
    int neg = negative.size();
    if(pos>neg){                     // if no of +ve > no of -ve (means -ve will over first)
        for(int i=0; i<neg; i++){         // putting first all -ve element
            arr[2*i+1]=negative[i];
        }
        for(int i=0; i<neg; i++){          // then +ve element equal to size of -ve element
            arr[2*i]=positive[i];
        }
        for(int i=0; i<pos-neg; i++){         // now the -ve array overs so putting remaining 
            arr[(pos)+i]=positive[neg+i];
        }
    }

    if(pos<neg){           //if no of +ve < no of -ve (means +ve will over first)
       for(int i=0; i<pos; i++){
            arr[2*i]=positive[i];
        }
        for(int i=0; i<pos; i++){
            arr[2*i+1]=negative[i];
        }
        for(int i=0; i<neg-pos; i++){
            arr[(neg)+i]=negative[pos+i];
        }
    }

    if(pos==neg){                  // both +ve and -ve are equal
        for(int i=0; i<n/2; i++){
            arr[2*i]=positive[i];
        }
        for(int i=0; i<n/2; i++){
            arr[2*i+1]=negative[i];
        }
    }
    return arr;
}
int main()
{
vector<int>arr={3,1,2,-5,2,-4};
vector<int>result=rearrangearray(arr);
for(auto it : result){
    cout<<it<<" ";
}
return 0;
}