class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        // [[1,3],[2,6],[8,10],[15,18]]
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){

                if(end>=intervals[i][0]){
                    end=max(end,intervals[i][1]);
                }
                else if(end<intervals[i][0]){
                    ans.push_back({start,end});
                    start=intervals[i][0];
                    end=intervals[i][1];
                }
        }
        ans.push_back({start,end});

        return ans;
    }
};