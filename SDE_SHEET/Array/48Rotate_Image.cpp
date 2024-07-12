class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int row=0;
        for(int i=0;i<m;i++){
            int col=0;
            for(int j=n-1;j>=0;j--){
                swap(matirx[j][i],matrix[row][col])
                col++;
            }
            row++;
        }

        matrix=ans;
    }
};

// Optmised
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reverse
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};