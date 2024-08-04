int MOD=1e9+7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // get subsets
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            long long temp=0;
            for(int j=i;j<nums.size();j++){
                temp+=nums[j];
                v.push_back(temp);
            }
        }
         
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=left-1;i<right;i++){
            ans=(ans+v[i])%MOD;
        }

        return (int)ans;
    }
};