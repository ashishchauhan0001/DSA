#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<vector<int>>& ans) {
    // row wise checking
    for (int i = 0; i < row; i++) {
        if (ans[i][col] == 1) return false;
    }

    int low = row, high = col;
    while (low >= 0 && high >= 0) {
        if (ans[low][high] == 1) return false;
        low--; high--;
    }
    low = row, high = col;
    while (low >= 0 && high < n) {
        if (ans[low][high] == 1) return false;
        low--;
        high++;
    }
    return true;
}

void solve(int row, int n, vector<vector<int>>& ans, vector<vector<vector<int>>>& solutions) {
    if (row == n) {
        // store the solution
        solutions.push_back(ans);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n, ans)) {
            ans[row][col] = 1;
            solve(row + 1, n, ans, solutions);
            ans[row][col] = 0;
        }
    }
    return;
}

vector<vector<vector<int>>> solveQueen(int n) {
    vector<vector<int>> ans(n, vector<int>(n,0));
    vector<vector<vector<int>>> solutions;
    solve(0, n, ans, solutions);
    return solutions;
}

int main()
{
    int n;
    cout << "Enter thr value of N" << endl;
    cin >> n;

    vector<vector<vector<int>>>vec=solveQueen(n);

        for (size_t i = 0; i < vec.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const auto& row : vec[i]) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
