class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        int temp=0;
        for(int i=0;i<=31;i++){
           int ans=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)) ans++;
            }
            if(ans%3!=0) temp+=(1<<i);
        }
        return temp;
    }
};