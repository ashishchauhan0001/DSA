int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int ans=1;
        int index=0;
        for(int i=1;i<n;i++){
            if(v[index].first<v[i].second){
                ans++;
                index=i;
            }
        }
      return ans;
    }