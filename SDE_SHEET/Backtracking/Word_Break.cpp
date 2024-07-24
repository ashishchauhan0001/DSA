class Solution {
public:

    bool solve(string str,unordered_set<string> &s,int i, vector<int> &dp){
        if(i==str.size()) return true;
        string temp="";
        if(dp[i]!=-1) return dp[i];

        for(int j=i;j<str.size();j++){
            temp+=str[j];
            if(s.find(temp)!=s.end()){
                if(solve(str,s,j+1,dp)) return dp[i]=true;
            }
        }

        return  dp[i]=false;
    }

    bool wordBreak(string st, vector<string>& wordDict) {
        unordered_set<string> s;
        vector<int> dp(st.size()+1,-1);
        for(auto it:wordDict){
            s.insert(it);
        }
        return solve(st,s,0,dp);

    }
};