typedef pair<int,pair<int,int>> ppi;
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> ans;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int n=A.size();
    priority_queue<ppi>pq;
    set<pair<int,int>> visited;
    visited.insert({0,0});
    pq.push({A[0]+B[0],{0,0}});
    while(C--){
        auto it=pq.top();
        pq.pop();
        
        int sum=it.first;
        int i=it.second.first;
        int j=it.second.second;
        
        ans.push_back(sum);
        if(i+1<n && visited.find({i+1,j})==visited.end()){
            pq.push({A[i+1]+B[j],{i+1,j}});
            visited.insert({i+1,j});
        }
        
        if(j+1<n && visited.find({i,j+1})==visited.end()){
            pq.push({A[i]+B[j+1],{i,j+1}});
            visited.insert({i,j+1});
        }
        
    }
    
    return ans;
    
}
