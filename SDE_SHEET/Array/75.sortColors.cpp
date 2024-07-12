// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int count0=0,count1=0,count2=0;
//         for(auto it:nums){
//             if(it==0) count0++;
//             else if(it==1) count1++;
//             else count2++;
//         }
//         int i=0;
//         while(count1||count2||count0){
//             if(count0){
//                 nums[i]=0;
//                 count0--;
//             }else if(count1){
//                 nums[i]=1;
//                 count1--;
//             }else{
//                 nums[i]=2;
//                 count2--;
//             }
//             i++;
//         }
//     }
// };


// DUTCH FLAG ALGORITHM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;   
            }
        }
    }
};