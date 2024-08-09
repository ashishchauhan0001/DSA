#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ans(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ans[i][j];
        }
    }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
 return 0;
}