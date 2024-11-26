#include<bits/stdc++.h>
using namespace std;


bool solve(string str1,string str2, int n,int m){
  
  if(m==0) return (n==0);
  if(n==0) return (str2.size()==1 && str2[0]=='*');
  
  // case 1 : ? or same
  if(str2[m-1]==str1[n-1] || str2[m-1]=='?') return solve(str1,str2,m-1,n-1);
  // case 2 : * or empty 
  if(str2[m-1]=='*') return (solve(str1,str2,n,m-1)||solve(str1,str2,n-1,m));

  return false; // not matching with anyone

}


int main()
{
   string str1,str2;
   cin>>str1>>str2;
   cout<<" True or False "<<solve(str1,str2,str1.size(),str2.size())<<endl;
 return 0;
}