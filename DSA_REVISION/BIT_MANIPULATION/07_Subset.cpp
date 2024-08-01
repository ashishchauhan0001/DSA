class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=pow(2,nums.size());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){ // for total no of subsets
            vector<int> v;
            for(int j=0;j<nums.size();j++){ // for getting the value from the place where it is set.
                if(i&(1<<j)){
                  v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};

