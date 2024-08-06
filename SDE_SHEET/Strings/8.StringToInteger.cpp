class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]==' ') i++;
            else break;
        }
        bool pos=(s[i]=='+');
        bool neg=(s[i]=='-');
        if(pos) i++;
        if(neg) i++;
         double ans=0;
        while(i<s.size() && s[i]>='0' && s[i]<='9' ){
                    ans=ans*10;
                    ans=ans+(s[i]-'0');
              i++;
        }

        if(neg){
            ans=ans*-1;
        }
        ans = (ans > INT_MAX) ? INT_MAX : ans;
        ans = (ans < INT_MIN) ? INT_MIN : ans;
        return ans;
    }
};