class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
             if(prices[i]>=start){
                ans=max(ans,prices[i]-start);
             }
             else{
                 start=prices[i];
             }
        }
        return ans;
    }
};