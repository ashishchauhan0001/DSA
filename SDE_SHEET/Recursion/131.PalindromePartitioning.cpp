/*
Notes:

Member Function Visibility:

Within a class, the member functions are visible to each other and can be called in any order as long as they are declared in the class definition.

Function Definition Order:

The order of function definitions inside the class does not matter for their usage as long as they are declared within the class.
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s,ans,ds,0);
        return ans;
    }
    bool isPal(string str,int start,int end){
        while(start<=end){
            if(str[start]==str[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }

    void solve(string s,vector<vector<string>> &ans,vector<string> &ds,int index){
        if(index==s.size()){
            ans.push_back(ds);
            return ;
        }

        for(int i=index;i<s.size();i++){
            if(isPal(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                solve(s,ans,ds,i+1);
                ds.pop_back();
            }
        }

        return;
    }
};