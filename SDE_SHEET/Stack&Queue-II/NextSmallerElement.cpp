#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> ans;
    st.push(arr[n-1]);
    for(int i=n-1;i>=0;i--){
       while(!st.empty() && st.top()>=arr[i]){
          st.pop();
       }
       int NSE=st.empty() ? -1 : st.top();
       ans.push_back(NSE);
       st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
  return ans;
}