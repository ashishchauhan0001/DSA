// Question 1:

// You are organizing a charity event and need to prepare gift baskets. Each gift basket must have a total value equal to a specific target amount. You have a list of distinct items, each with a fixed price, and you want to know all possible ways to combine these items to reach the exact target value. 
// Each item can be chosen an unlimited number of times, as long as the total value of the basket equals the target. 
// Two combinations are considered different if the frequency of at least one item is different. Your goal is to return a list of all unique combinations of items that can form a basket with the exact target value. It is guaranteed that the number of unique combinations for the given input will be fewer than 150. 

// Input: items = [2,3,5], targetAmount = 8 
// Output: [[2,2,2,2],[2,3,3],[3,5]] 

// Input: items = [2], targetAmount = 1 
// Output: []


#include<bits/stdc++.h>
using namespace std;



void fun(vector<int>&arr,vector<int> &ds,vector<vector<int>> &ans,int i,int target){
 
//  if(i>s.szie)

 if(i==arr.size()){
    if(target==0){
    ans.push_back(ds);
    }
    return;
 }

 if(target>=arr[i]){
    ds.push_back(arr[i]);
    fun(arr,ds,ans,i,target-arr[i]);
    ds.pop_back();
 }
 
 fun(arr,ds,ans,i+1,target);

return ;

}

// T.C--> O(N^n)  (N!)

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int>ds;
    vector<vector<int>>ans;
    fun(arr,ds,ans,0,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


 return 0;
}



//  [2,3,5]  target=8
//  ds={2,3,3} 
// 
 