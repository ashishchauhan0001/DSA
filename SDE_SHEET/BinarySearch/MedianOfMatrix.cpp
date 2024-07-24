int blackBox(vector<vector<int>> &matrix,int mid){
        
        int count=0;
        for(int i=0;i<matrix.size();i++){
            auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
            int index=it-matrix[i].begin(); // getting the index bcz it is a pointer
            count+=index;
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here       
        int low=1;
        int high=2000;
        int req=(R*C)/2;
        
        while(low<=high){
            int mid=(low+high)/2;
            int val=blackBox(matrix,mid);
            if(val<=req) low=mid+1;
            else high=mid-1;
        }
        
        return low;
    }