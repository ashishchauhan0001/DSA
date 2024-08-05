class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        for(auto it:arr){
            m[it]++;
        }
        for(auto it:arr){
           if(m[it]==1 && k==1){
                return it;
           }else if(m[it]==1 && k!=1){
            k--;
           }
        }
        return "";
    }
};