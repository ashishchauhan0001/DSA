int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=0;
    	int j=0;
    	
    	int ans=0;
    	int count=0;
    	while(i<n&&j<n){
    	    if(arr[i]<=dep[j]){
    	        i++;
    	        count++;
    	    }else{
    	        j++;
    	        count--;
    	    }
    	    ans=max(ans,count);
    	}
    	return ans;
    }