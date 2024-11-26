#include<bits/stdc++.h>
using namespace std;

void Isort(vector<int> &arr){

    for(int i=0;i<arr.size();i++){
        int prev=i-1;
        int curr=arr[i];
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}

int main()
{
    vector<int> arr={5,2,56,7,22,1};
    Isort(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
 return 0;
}