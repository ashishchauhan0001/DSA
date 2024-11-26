#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr,int low,int mid,int high){

    int lstart=low;
    int rstart=mid+1;
    vector<int> temp;
    while(lstart<=mid && rstart<=high){
        if(arr[lstart]<=arr[rstart]){
            temp.push_back(arr[lstart]);
            lstart++;
        }else{
            temp.push_back(arr[rstart]);
            rstart++;
        }
    }
    while(lstart<=mid){
        temp.push_back(arr[lstart]);
        lstart++;
    }
    while(rstart<=high){
        temp.push_back(arr[rstart]);
        rstart++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}



void divide(vector<int> &arr,int low,int high){
    if(low>=high) return ;
    int mid=(low+high)/2;
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
}


int main()
{
    vector<int> arr={6,34,62,12,35,14,56};
    divide(arr,0,arr.size()-1);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

 return 0;
}