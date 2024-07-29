class Solution {
public:
bool check(char ch,char s){
    return ((ch==')'&&s=='(')||(ch=='}'&&s=='{')||(ch==']'&&s=='['));
}
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='('||ch=='{'||ch=='[') st.push(ch);
            else if(ch==')'||ch=='}'||ch==']'){
                if(st.empty()) return false;
                if(check(ch,st.top())){
                    st.pop();
                }
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};