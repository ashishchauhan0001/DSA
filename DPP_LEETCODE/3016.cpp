class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> v(26,0);
        for(auto it:word){
            v[it-'a']++;
        }

        sort(v.rbegin(),v.rend()); // sort frequency wise

        for(int i=0;i<v.size();i++){
            ans+=(i/8 + 1) * v[i]; 
        }

        return ans;

    }
};