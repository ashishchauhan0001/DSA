class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>p;
        for(int i=0;i<names.size();i++){
            p.push_back({heights[i],names[i]});
        }
        sort(p.rbegin(),p.rend());
        int i=0;
        for(auto it:p){
            names[i]=it.second;
            i++;
        }

        return names;
    }
};