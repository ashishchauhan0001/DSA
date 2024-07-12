int maxSubArray(vector<int>& nums) {
  
  int sum=0;
  int ans=INT_MIN;
  for(int i=0;i<nums.size();i++){
    sum+=nums[i];
    if(sum>ans){
        ans=sum;
    }
    if(sum<0){
        sum=0;
    }
  }
return ans;
}

int maxSubArrayPrint(vector<int>& nums) {
  
  int sum=0;
  int ans=INT_MIN;
  int startInd=-1,endInd=-1,temp=0;

  for(int i=0;i<nums.size();i++){
    sum+=nums[i];
     
     if(sum=0) temp=i;

    if(sum>ans){
        ans=sum;
        startInd=temp;
        endInd=i;
    }
    if(sum<0){
        sum=0;
    }
  }
return ans;
}

