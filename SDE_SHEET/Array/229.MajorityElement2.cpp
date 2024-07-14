class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        int n=nums.size();
        for(auto it:nums){
            if(cnt1==0&&it!=ans2){
                ans1=it;
            }
            else if(cnt2==0&&it!=ans1){
                ans2=it;
            }

            if(it==ans1) cnt1++;
            else if(it==ans2) cnt2++;
            else {
                cnt1--; 
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1=0,cnt2=0;
        for(auto it:nums){
            if(it==ans1) cnt1++;
            else if(it==ans2) cnt2++;
        }
        if(cnt1>n/3)  ans.push_back(ans1);
        if(cnt2>n/3)  ans.push_back(ans2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};