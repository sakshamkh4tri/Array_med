// you are given a array for example {102,4,100,1,101,3,2,1,1}
// you have to check the length of the every consecutive sequence like (100,101,102)--3  , (1,2,3,4)---4
// max length is 4 so it should return 4

// brute force

// #include<bits/stdc++.h>
// using namespace std;
// int longestsubarr(vector<int>&arr){
//     int n = arr.size();
//     int count=0;             // for counting is how many arr[i]+j+1 element exists for eg if i=1 then it 2,3,4 exists in arr so count becomes 3
//     int largest=0;                      // for storing the largest consecutive subarray
//     for(int i=0; i<n; i++){                // picking a number from starting to end one by one
//         for(int j=0; j<n; j++){            //  for checking the consecutive numbers 
//             int num=arr[i]+j+1;
//              bool found=false;                  // for keeping a track that the num we are searching id foumded or not
//             for(int k=0; k<n; k++){                // searching that consecutive numbers in array
//                 if(arr[k]==num){
//                     found=true;       // if that num is founded it becomes true
//                     count++;
//                     largest=max(largest,count);
//                     break;
//                 }
//             }
//             if(!found){           //  if found remains false then it means the num is not found then  count resets
//                 count=0;
//                 break;
//             }
            
//         }

//     }
//     if(arr.size()==0) return largest;
//     return largest+1;              // +1 because count doesnt counts the arr[i];
// }
// int main()
// {
// vector<int>arr={1,2,2,3};
// cout<<longestsubarr(arr);

// return 0;
// }


// better solution     o(nlogn) + o(n)
// #include<bits/stdc++.h>
// using namespace std;
// int longestsubarr(vector<int>&arr){
//     int n= arr.size();
//     sort(arr.begin(),arr.end());             // sort it first
//     int count=0; 
//     int lastsmallest=INT_MIN;
//     int largest=0;
//     for(int i=0; i<n; i++){              // iterate through every element
//         int num = arr[i];
//         if(num==lastsmallest+1){          
//             count ++;
//             lastsmallest=arr[i];
//             largest=max(largest,count);
//         }
//         else if(num!=lastsmallest+1 && num!=lastsmallest){
//             count=0;
//             lastsmallest=arr[i];
//         }
//     }
//     if(largest==0) return largest;    // edge case if array is empty
//     return largest+1;
// }
// int main()
// {
//     vector<int>arr={};
//     cout<<longestsubarr(arr);
// return 0;
// }

// optimal solution

#include<bits/stdc++.h>
using namespace std;
int longestsubarray(vector<int>&arr){
    int n= arr.size();
    int largest=INT_MIN;
    set<int>st;
    if(n==0) return 0;        // edge case if array is empty
    for(int i=0; i<n; i++){              // putting element in set
        st.insert(arr[i]);
    }
    for(auto it : st){     // iterating to every element of set
        if(st.find(it-1)==st.end()){             // if curr element -1 is not found 
                int num= it;
                int count=1;                     // start counting
            while(st.find(num+1)!=st.end()){            // checking if curr element +1 exists in set if yes then inc count
                num=num+1;
                count=count+1;
            }
            largest=max(largest,count);
        }
    }
    return largest;
}
int main()
{
vector<int>arr={102,4,100,1,101,3,2,1,1};
cout<<longestsubarray(arr);
return 0;
}