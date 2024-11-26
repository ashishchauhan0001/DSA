#include<bits/stdc++.h>
using namespace std;


// bool solve(string str1,string str2, int n,int m){
  
//   if(m==0) return (n==0);
//   if(n==0) return (str2.size()==1 && str2[0]=='*');
  
//   // case 1 : ? or same
//   if(str2[m-1]==str1[n-1] || str2[m-1]=='?') return solve(str1,str2,m-1,n-1);
//   // case 2 : * or empty 
//   if(str2[m-1]=='*') return (solve(str1,str2,n,m-1)||solve(str1,str2,n-1,m));

//   return false; // not matching with anyone

// }




bool solve(string &str1, string &str2, int n, int m, vector<vector<int>> &dp) {
    // Base case: if both strings are empty
    if (m == 0) return (n == 0);

    // If result is already computed
    if (dp[n][m] != -1) return dp[n][m];

    // If the text is empty, check if the remaining pattern is all '*'
    if (n == 0) {
        for (int i = 0; i < m; i++) {
            if (str2[i] != '*') return dp[n][m] = false;
        }
        return dp[n][m] = true;
    }

    // Case 1: Characters match or pattern has '?'
    if (str2[m - 1] == str1[n - 1] || str2[m - 1] == '?') {
        return dp[n][m] = solve(str1, str2, n - 1, m - 1, dp);
    }

    // Case 2: Pattern has '*'
    if (str2[m - 1] == '*') {
        return dp[n][m] = solve(str1, str2, n, m - 1, dp) || solve(str1, str2, n - 1, m, dp);
    }

    // Case 3: No match
    return dp[n][m] = false;
}

bool wildCard(string &txt, string &pat) {
    int n = txt.size();
    int m = pat.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(txt, pat, n, m, dp);
}



int main()
{
   string str1,str2;
   cin>>str1>>str2;
   vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),-1));
   cout<<" True or False "<<solve(str1,str2,str1.size(),str2.size(),dp)<<endl;
 return 0;
}