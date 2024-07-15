// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         set<vector<int>>st;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 set<long long>s;
//                 for(int k=j+1;k<n;k++){
//                     long long sum=nums[i]+nums[j];
//                     sum+=nums[k];
//                     long long fourth=target-sum;
//                     if(s.find(fourth)!=s.end()){
//                         vector<int> v={nums[i],nums[j],nums[k],(int)fourth};
//                         sort(v.begin(),v.end());
//                         st.insert(v);
//                     }
//                     s.insert(nums[k]);
//                 }
//             }
//         }

//         vector<vector<int>> ans(st.begin(),st.end());

//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
          for(int j=i+1;j<n;j++){
            if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; // it needs to be move 
                        l--;// same

                        while(k<l&&nums[k]==nums[k-1]) k++;
                        while(l>k&&nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};