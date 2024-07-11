class Solution {
public:
// void makeZero(vector<vector<int>>& matrix,int row,int col,int n,int m){
    
//     for(int i=0;i<m;i++){// row
//         matrix[row][i]=0;
//     }

//     for(int it=0;it<n;it++){ // col
//         matrix[it][col]=0;
//     }
//  }
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     vis[i][j]=1;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j]==1){
//                     makeZero(matrix,i,j,n,m);
//                 }
//             }
//         }
//     }

    void setZeroes(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; // treat as aux row
                    if(j!=0){
                        matrix[0][j]=0; // treat as aux col
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }


    }
};