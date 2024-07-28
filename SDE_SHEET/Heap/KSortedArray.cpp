// This is also avail as Nearly Sorted Array.

vector <int> nearlySorted(int nums[], int num, int k){
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int> temp(num,0);
        int j=0;
        for(int i=0;i<num;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                temp[j]=pq.top();
                j++;
                pq.pop();
            }
        }
        while(!pq.empty()){
            temp[j]=pq.top();
            j++;
            pq.pop();
        }
        
        return temp;
    }