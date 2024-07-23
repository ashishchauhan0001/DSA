void solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis,
           string &ans, int n, vector<string> &sol)
{
    if (i == n - 1 && j == n - 1)
    {
        sol.push_back(ans);
        return;
    }

    // right
    if (j + 1 < n && mat[i][j + 1] == 1 && !vis[i][j + 1])
    {
        vis[i][j] = 1;
        ans += "R"; // you can just do inline recusion then no need to pop out the element.
        solve(i, j + 1, mat, vis, ans, n, sol);
        ans.pop_back();
        vis[i][j] = 0;
    }
    // left
    if (j - 1 >= 0 && mat[i][j - 1] == 1 && !vis[i][j - 1])
    {
        vis[i][j] = 1;
        ans += "L";
        solve(i, j - 1, mat, vis, ans, n, sol);
        vis[i][j] = 0;
        ans.pop_back();
    }
    // up
    if (i - 1 >= 0 && mat[i - 1][j] == 1 && !vis[i - 1][j])
    {
        vis[i][j] = 1;
        ans += "U";
        solve(i - 1, j, mat, vis, ans, n, sol);
        vis[i][j] = 0;
        ans.pop_back();
    }
    // down
    if (i + 1 < n && mat[i + 1][j] == 1 && !vis[i + 1][j])
    {
        vis[i][j] = 1;
        ans += "D";
        solve(i + 1, j, mat, vis, ans, n, sol);
        vis[i][j] = 0;
        ans.pop_back();
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    // Your code goes here
    string ans = "";
    int n = mat.size();
    vector<string> sol;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (mat[0][0] == 1)
        solve(0, 0, mat, vis, ans, n, sol);
    return sol;
}