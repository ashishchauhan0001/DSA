bool static comparision(Job a,Job b){
         return (a.profit>b.profit);
     }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comparision);
        int max_dead=INT_MIN;
        for(int i=0;i<n;i++){
            max_dead=max(max_dead,arr[i].dead);
        }
        vector<int>aux(max_dead+1,-1);
        int jobs=0;
        int totalProfit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(aux[j]==-1){
                    aux[j]=arr[i].id;
                    jobs++;
                    totalProfit+=arr[i].profit;
                    break;
                }
            }
        }
        
        return {jobs,totalProfit};
    } 