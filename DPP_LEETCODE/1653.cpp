class Solution {
public:
    int minimumDeletions(string s) {
        int ans=0;
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty() && (st.top()=='b' && s[i]=='a')){
                ans++;
                st.pop();
            }
             else st.push(s[i]);
        }
        return ans;
    }
};