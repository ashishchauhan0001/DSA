class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=INT_MAX;
        vector<int> a;
        vector<int>b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini=min(mini,matrix[i][j]);
            }
            a.push_back(mini);
            mini=INT_MAX;
        }
        mini=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mini=max(mini,matrix[j][i]);
            }
            b.push_back(mini);
            mini=INT_MIN;
        }

        vector<int> luckyNumbers;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == a[i] && matrix[i][j] == b[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};