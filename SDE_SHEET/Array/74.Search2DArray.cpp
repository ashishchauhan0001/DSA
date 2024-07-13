 // this formula based sols only used when the last row's last element is greater than next row's first element.
 // most optimal
 bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here int n=matrix.size();
        int low=0;
        int high=(long long)(m*n)-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m; // formula
            int col=mid%m; // formula
            if(matrix[row][col]==x) return true;
            else if(matrix[row][col]<x){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return false;
    }