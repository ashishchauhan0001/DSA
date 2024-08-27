#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<bool>arr(n,true);
    int i=2;
    while(i<n){
        int inc=i+1;
        for(int j=inc;j<n;j=j+inc){
            arr[j]=!arr[j];
        }
        i++;
    }

    for(auto it:arr){
        cout<<it<<" ";
    }
 return 0;
}