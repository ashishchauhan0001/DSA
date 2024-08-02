class Solution {
public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis=grid;
        queue<pair<pair<int,int>,int>>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1) cnt++;
            }
        }
        
        int time=0,count=0;
        vector<int>delr={0,0,1,-1};
        vector<int>delc={1,-1,0,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(t,time);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=row+delr[i];
                int nc=col+delc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==1&&grid[nr][nc]==1){
                    count++;
                    q.push({{nr,nc},time+1});
                    vis[nr][nc]=2;
                }
            }
        
        }
        if(count!=cnt) return -1;
        
        
        return time;
    }
};
