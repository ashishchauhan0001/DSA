#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  unordered_map<int,int>m;
  int ans=0;
  int maxi=0;
  for(int i=0;i<n;i++)
  {
   m[arr[i]]++;
   maxi=max(maxi,m[arr[i]]);
  }

  for(int i=0;i<n;i++)
  {
    if(maxi==m[arr[i]])
    {
        ans=arr[i];
        cout<<"repeated element is : "<<ans;
        break;
    }
  }
    return 0;
}