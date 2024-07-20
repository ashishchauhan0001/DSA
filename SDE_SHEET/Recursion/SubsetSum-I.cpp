void fun(int i,vector<int> &arr,vector<int> &ds,int sum){
       
       if(i>arr.size()) return ;
       
       if(i==arr.size()){
           ds.push_back(sum);
           return;
       }
       
       fun(i+1,arr,ds,sum+arr[i]);
       fun(i+1,arr,ds,sum);
       return ;
   }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ds;
        fun(0,arr,ds,0);
        return ds;
    }