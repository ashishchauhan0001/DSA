int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        int ans=0;
        if(k!=0){
            for(auto it:m){
                if(m.find(it.first+k)!=m.end()){
                    ans++;
                }
            }
        }else{
            for(auto it:m){
                if(it.second>1) ans++;
            }
        }
        return ans;
    }