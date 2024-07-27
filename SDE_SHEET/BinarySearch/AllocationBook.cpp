
int blackBox(int mid,int m,vector<int> &arr){
    int pages=0;
    int student=1;
    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]<=mid){
            pages+=arr[i];
        }
        else{
            student++;
            pages=arr[i];
        }
    }
    return student;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int ans=-1;
    while(low<=high){ 
        int mid=(low+high)>>1;
        int students=blackBox(mid,m,arr);
        if(students>m){
             low=mid+1;
        }
        else{ // answer alwys = wale side
             ans=mid;
             high=mid-1;
        }   
    }
    return ans;
}