#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high){

   int x=low;
   int pivot=arr[high];
   for(int i=low;i<high;i++){
     if(arr[i]<pivot){
        swap(arr[i],arr[x]);
        x++;
     }
   }
   swap(arr[x],arr[high]);
   return x;

}



void divide(vector<int> &arr,int low,int high){
  if(low>=high) return ;
  int x=partition(arr,low,high);
  divide(arr,low,x-1);
  divide(arr,x+1,high);
}


int main()
{
    vector<int> arr={6,34,62,12,35,14,56};
    divide(arr,0,arr.size()-1);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}