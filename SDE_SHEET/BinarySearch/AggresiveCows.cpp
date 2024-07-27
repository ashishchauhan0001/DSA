

bool blackBox(int mid,int k,vector<int> &stalls){
     
     int count=1;
     int index=0;
     for(int i=0;i<stalls.size();i++){
         if(stalls[i]-stalls[index]>=mid){ // zyda distance hoga to bhe chlega boss!
             count++;
             index=i;
         }
     }
     if(count>=k) return true;
     return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int ans=0;
    int low=1;
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int high=stalls[n-1]-stalls[0]; // last khunta - first khunta
    while(low<=high){
        int mid=(low+high)>>1;
        bool dist=blackBox(mid,k,stalls);
        if(dist){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}