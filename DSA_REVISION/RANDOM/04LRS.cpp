// Longest Repeating Subsequence

int LongestRepeatingSubsequence(string str) {
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match and indices are different
            if (str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Otherwise, take the maximum of skipping either character
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
