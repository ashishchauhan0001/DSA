class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                start=max(start,m[s[i]]+1); // start from its next occurence..
            }
            
            ans=max(ans,i-start+1);
            m[s[i]]=i;
        }

        return ans;
    }
};