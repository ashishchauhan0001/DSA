class Solution {
public: // freq--> increasing order
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>> v;
        unordered_map<int,int> m;
        for(auto it:nums) m[it]++;
        for(auto it:m) v.push_back({it.second,it.first});
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i].first==v[j].first){
                    if(v[i].second<v[j].second){
                        swap(v[i],v[j]);
                    }
                }
                else if(v[i].first>v[j].first){
                        swap(v[i],v[j]);
                    }
            }
        }
        int i=0;
        for(auto it:v){
            for(int j=0;j<it.first;j++){
                nums[i]=it.second;
                i++;
            }
        }
        return nums;
    }
};