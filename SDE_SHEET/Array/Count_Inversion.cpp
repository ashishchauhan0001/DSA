#include <bits/stdc++.h> 

long long ans=0;
void merge(vector<long long> &arr,long long low,long long mid,long long high)
{
    long long left=low;
    long long right=mid+1;
    vector<long long> temp;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            ans+=(mid-left+1);
            right++;
           // conversions+=(mid-left)+1;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    for(long long i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }

}


void divide(vector<long long> &arr,long long low,long long high)
{
    if(low>=high) return;
    long long mid=(low+high)/2;
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
     vector<long long> nums(n);
     for(int i=0;i<n;i++){
         nums[i]=arr[i];
     }   

    divide(nums,0,n-1);
    
    return ans;
}