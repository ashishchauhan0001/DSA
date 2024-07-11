class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        string str1="./";
        string str2="../";
        for(int i=0;i<logs.size();i++){
            if(logs[i]==str1){
                ans+=0;
            }
            else if(logs[i]==str2){
                if(ans!=0) ans-=1;
            }
            else{
                ans+=1;
            }
        }
        return ans;
        
    }
};