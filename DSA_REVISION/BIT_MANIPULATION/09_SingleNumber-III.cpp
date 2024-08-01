class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xori=0; // this is for the prevention of overflow
        for(auto it:nums) xori=xori^it;
        int rightMostbit=(xori&(xori-1))^xori; // bcz of this xori-1 in case of xori= INT_MIN ??
        
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rightMostbit) b1=b1^nums[i];
            else b2=b2^nums[i];
        }

        return {b1,b2};
    }
};