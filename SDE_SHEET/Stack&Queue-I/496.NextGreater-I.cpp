// Brute Force
class Solution {
public:
    int check(int i,vector<int> v){
        int ans=-1;
        for(int j=i+1;j<v.size();j++){
            if(v[j]>v[i]){
                ans=v[j];
                break;
            }
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),0);
        int index=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int val=check(j,nums2);
                    ans[index]=val;
                    index++;
                }
            }
        }
        return ans;
    }
};


// Optimal Using Stack 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        stack<int>s;
        s.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]) s.pop();

            int NGE=s.empty()? -1 : s.top();
            m[nums2[i]]=NGE; 
            s.push(nums2[i]);
        }

        vector<int> ans;
        for(auto it:nums1){
            if(m.find(it)!=m.end()){
                ans.push_back(m[it]);
            }
        }

        return ans;

    }
};