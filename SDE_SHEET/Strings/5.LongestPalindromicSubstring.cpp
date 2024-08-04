class Solution {
public:
    string longestPalindrome(string s) {
        int si=0;
        int ans=1;
        int low,high;
        int n=s.size();

        for(int i=1;i<s.size();i++){

            // even
            low=i;
            high=i-1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(high-low+1 > ans){
                    si=low;
                    ans=(high-low)+1;
                }
                low--;
                high++;
            }

            // odd case
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                 if(high-low+1 > ans){
                si=low;
                ans=(high-low)+1;
                 }
                 low--;
                 high++;
            }
            
        }

        return s.substr(si,ans);
    }
};