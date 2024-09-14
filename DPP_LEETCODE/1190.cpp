class Solution {
public:
   
 c
    }
}
string reverseParentheses(std::string s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else if (s[i] == ')') {
            int start = stk.top();
            stk.pop();
            reverseSubstring(s, start, i);
        }
    }
    string result="";
    for (char ch : s) {
        if (ch != '(' && ch != ')') {
            result += ch;
        }
    }
    return result;
}
};
