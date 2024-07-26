class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
	    
	    vector<vector<int>> dist(n,vector<int>(n,1e9));
      
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int i=0;i<n;i++)
        {
            dist[i][i]==0;
        }

	    for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
	            }
	        }
	    }

        int min_city=0,max_val=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&dist[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }

            if(count<=max_val)
            {
                min_city=i;
                max_val=count;
            }
        }
	    return min_city;
	    
	    
	    
	   
    }
};