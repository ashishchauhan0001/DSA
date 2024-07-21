class Solution {
public:
// "45320" -->
    string getSmallestString(string s) {
        for(int i=1;i<s.size();i++){
            if((s[i]-'0')%2==0 && (s[i-1]-'0')%2==0){
                if((s[i]-'0')<(s[i-1]-'0')){
                    swap(s[i],s[i-1]);
                    break;
                }
                }else if((s[i]-'0')%2!=0 && (s[i-1]-'0')%2!=0){
                    if((s[i]-'0')<(s[i-1]-'0')){
                    swap(s[i],s[i-1]);
                    break;
                    }
                }
            }
            return s;
        }
    
};