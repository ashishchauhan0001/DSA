void solve(vector<vector<int>> &ans,vector<int> &ds,vector<int>&nums,int target,int i){

        if(i==nums.size()){
            if(target==0){
                ans.push_back(ds);
            }

            return ;
        }

        if(target>=nums[i]){ // pick
            ds.push_back(nums[i]);
            solve(ans,ds,nums,target-nums[i],i);
            ds.pop_back();
        }

        solve(ans,ds,nums,target,i+1); // not pick

        return ;

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,nums,target,0);

        return ans;
    }