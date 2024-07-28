typedef pair<int,int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto it:nums) m[it]++;

        priority_queue<pi,vector<pi>,greater<pi>>pq;

        for(auto it:m){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};