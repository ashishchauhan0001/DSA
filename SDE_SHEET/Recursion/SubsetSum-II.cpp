// Better Solution
void solve(vector<int> &nums,vector<int>&ds,set<vector<int>>&s,int i){
        if(i==nums.size()){
            s.insert(ds);
            return;
        }

        ds.push_back(nums[i]);
        solve(nums,ds,s,i+1);
        ds.pop_back();

        solve(nums,ds,s,i+1);

        return;

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(nums,ds,s,0);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;

    }

    // Optimal Solution
void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds,int index){

         ans.push_back(ds);

        for(int i=index;i<nums.size();i++){
            if(i!=index&&nums[i]==nums[i-1]) continue; // to avoid duplication..( 3!=3 too i++ hi hoga i.e 4,5,6..)
            ds.push_back(nums[i]);
            solve(nums,ans,ds,i+1);
            ds.pop_back();
        }

        return ;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> ds;
      sort(nums.begin(),nums.end()); // saare dupliactes sath aajae
      solve(nums,ans,ds,0);
      return ans;   
    }
    