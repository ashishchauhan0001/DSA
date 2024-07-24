class Solution {
public: // [1,1,2,2,3,3,4,4]
        //  e o e o e o e o   
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1; // to avoid overflow while accessing mid+1;
        int high=nums.size()-2; // to avoid overflow
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[n-2]) return nums[n-1];

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]) return nums[mid];
            else if(mid%2!=0 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};