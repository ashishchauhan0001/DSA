class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;
        for(int i=2;i<=n;i++){
            char say=ans[0];
            int cnt=1;
            string temp="";
            for(int j=1;j<ans.size();j++){
                 if(ans[j]==say){
                    cnt++;
                 }else{
                    temp+=to_string(cnt)+say;
                    cnt=1;
                    say=ans[j];
                 }
            }
            temp+=to_string(cnt)+say;
            ans=temp;
        }

        return ans;
    }
};