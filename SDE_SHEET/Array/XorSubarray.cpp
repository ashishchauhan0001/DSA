#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    int xr=0,ans=0;
    map<int,int> mp;
    mp[xr]++;
    for(int i=0;i<arr.size();i++){
        xr^=arr[i];
        int t=xr^x;
        ans+=mp[t];
        mp[xr]++;
    }
    return ans;
    
}