#include <iostream>
#include<unordered_map>
using namespace std;

void Intersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
         map[arr1[i]]++; 
    }
    
    for(int i=0;i<m;i++)
    {
        if(map[arr2[i]]>=1)
        {
           cout<<arr2[i]<<endl; 
            map[arr2[i]]--;
        } 
        else
        {
            continue;
        }
    }
   
}


void fun(int arr1[],int arr2[],int n,int m){
   unordered_map<int,int> mp;
   for( int i=0;i<n;i++){
        mp[arr1[i]]++;
   }

   for(int i=0;i<m;i++){
    if(mp.count(arr2[i])>0){
        cout<<arr2[i]<<" ";
    }
   }
   return ;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    Intersection(arr1,arr2,n,m);
    fun(arr1,arr2,n,m);
    return 0;
}