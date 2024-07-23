bool isValid(int node,bool graph[101][101],int color,vector<int> &vis){
        
        for(int i=0;i<vis.size();i++){ // checking with the other nodes..
            if(i!=node&&graph[i][node]==1&&vis[i]==color){
                return false;
            }
        }
        return true;
    }
    
    
    bool solve(int node,bool graph[101][101],int n,int m,vector<int> &vis){
        if(node==n) return true;
        
        for(int i=1;i<=m;i++){
            if(isValid(node,graph,i,vis)){
                vis[node]=i;
               if(solve(node+1,graph,n,m,vis)) return true;
               vis[node]=0; // backtrack  we can skip this step and solution still works but it is good practice to re assign vis to zero
            }
        }
        return false;
    }
       
   
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> vis(n,0);
        if(solve(0,graph,n,m,vis)){
            return true;
        }
        
        return false;
    }