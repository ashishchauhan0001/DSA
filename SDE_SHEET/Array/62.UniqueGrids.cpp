class Solution {
public:
    int fun(int i,int j,int n,int m,vector<vector<int>> &dp){
       if(i==0&&j==0) return 1;
       if(i<0||j<0) return 0;
       if(dp[i][j]!=-1) return dp[i][j];

       int left=fun(i,j-1,n,m,dp);
       int up=fun(i-1,j,n,m,dp);

       return dp[i][j]=(left+up);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,0,0,dp);
    }
};