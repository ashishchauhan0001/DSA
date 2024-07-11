class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas;
        for(int i=0;i<numRows;i++){
            vector<int>v(i+1,1);
            for(int j=1;j<i;j++){
                v[j]=pas[i-1][j]+pas[i-1][j-1];
            }
            pas.push_back(v);
        }

        return pas;
    }
};