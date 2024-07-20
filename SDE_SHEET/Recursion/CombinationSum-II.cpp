// Brute Force with TLE

void solve(set<vector<int>> &s,vector<int> &ds,vector<int>&nums,int target,int i){

        if(i==nums.size()){
            if(target==0){
                s.insert(ds);
            }

            return ;
        }

        if(target>=nums[i]){ // pick
            ds.push_back(nums[i]);
            solve(s,ds,nums,target-nums[i],i+1);
            ds.pop_back();
        }

        solve(s,ds,nums,target,i+1); // not pick

        return ;

    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(s,ds,nums,target,0);
        for(auto it:s){
            ans.push_back(it);
        }

        return ans;
    }



    // Optimal Solution

    void solve(vector<vector<int>> &ans,vector<int> &ds,vector<int>&nums,int target,int index){

            if(target==0){
               ans.push_back(ds);
               return ;
            }

        for(int i=index;i<nums.size();i++){
            if(i!=index&&nums[i-1]==nums[i]) continue;
            
            if(target>=nums[i]){ // we can add else condition to break the loop for more optimization..
            ds.push_back(nums[i]);
            solve(ans,ds,nums,target-nums[i],i+1);
            ds.pop_back();
            }
        }

        return ;

    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(ans,ds,nums,target,0);
        return ans;
    }
};