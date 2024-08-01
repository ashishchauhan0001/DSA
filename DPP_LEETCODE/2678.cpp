class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto it:details){
            string str=it;
            if((str[11]>='6' && str[12]>'0')||(str[11]>'6'&&str[12]>='0')) ans++;
        }

        return ans;
    }
};