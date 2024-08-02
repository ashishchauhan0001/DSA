vector<int> maxOfMin(int arr[], int n) {
    vector<int> nextSE(n), prevSE(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        nextSE[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    
    while (!s.empty()) s.pop();
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        prevSE[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    vector<int> ans(n + 1, 0);

 
    for (int i = 0; i < n; ++i) {
        int len = nextSE[i] - prevSE[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }


    for (int i = n - 1; i >= 1; --i)
        ans[i] = max(ans[i], ans[i + 1]);

    ans.erase(ans.begin());

    return ans;
}