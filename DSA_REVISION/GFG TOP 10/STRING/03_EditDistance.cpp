#include <bits/stdc++.h>
using namespace std;

// horse
// ros

int solve(string str1, string str2, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0)
        return m + 1;
    if (m < 0)
        return n + 1;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (str1[n] == str2[m])
        return dp[n][m] = 0 + solve(str1, str2, n - 1, m - 1, dp);

    return dp[n][m] = 1 + min({solve(str1, str2, n, m - 1, dp), solve(str1, str2, n - 1, m, dp), solve(str1, str2, n - 1, m - 1, dp)});
}

// int solve(string str1, string str2, int n, int m)
// {
//     if (n < 0)
//         return m + 1;
//     if (m < 0)
//         return n + 1;

//     if (str1[n] == str2[m])
//         return 0 + solve(str1, str2, n - 1, m - 1);

//     return 1 + min({solve(str1, str2, n, m - 1), solve(str1, str2, n - 1, m), solve(str1, str2, n - 1, m - 1)});
// }

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << "Minimum Operation required : " << solve(str1, str2, str1.size() - 1, str2.size() - 1) << endl;
    return 0;
}