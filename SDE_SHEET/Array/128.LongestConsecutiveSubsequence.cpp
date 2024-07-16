class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1;
        int ans=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i])
            {
                 continue;
            }    
            else if(nums[i+1]-1==nums[i])
            {
                 cnt++;
            }  
            else{
            cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};

//[9,1,4,7,3,-1,0,5,8,-1,6]
//-1 -1 0 1 3 4 5 6 7 8 9
// ans -1 0 1 == 3
// 3 4 5 6 7 8 9 == 7


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(nums.size()==0) return 0;
        int ans=1;
        for(auto it:nums){
            s.insert(it); // unique and sorted O(1) complexity
        }

        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int curr=it;
                int cnt=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    cnt++;
                }
                    ans=max(ans,cnt);
            }
        }

        return ans;

    }
};