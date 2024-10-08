#include <bits/stdc++.h> 

class PriorityQueue{
    vector<int>pq;
 public:
   PriorityQueue() {

   }
   
   void insert(int element)
   {
    pq.push_back(element);
    int childIndex=pq.size()-1;

    while(childIndex>0){
        
    int parentIndex=(childIndex-1)/2;  

    if(pq[childIndex]<pq[parentIndex])
    {
        int temp=pq[childIndex];
        pq[childIndex]=pq[parentIndex];
        pq[parentIndex]=temp;
    }
    else{
        break;
    }
    childIndex=parentIndex;

   }
   }

   int removeMin() {
        int ans = pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while( leftChildIndex < pq.size()){
            int minIndex=parentIndex;
        if(pq[minIndex]>pq[leftChildIndex])
            minIndex=leftChildIndex;           
       if (rightChildIndex < pq.size() && pq[rightChildIndex]<pq[minIndex]){
            minIndex = rightChildIndex;
        }
        if(minIndex==parentIndex)
        {
            break;
        }

        int temp=pq[minIndex];
        pq[minIndex]=pq[parentIndex];
        pq[parentIndex]=temp;
        parentIndex=minIndex;
		leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
        
    }
        return ans;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    PriorityQueue pq;
    for (int i = 0; i < q.size(); i++) {
        if (q[i][0] == 0) {
            pq.insert(q[i][1]);
        } else if (q[i][0] == 1) {
            int val = pq.removeMin();
            ans.push_back(val);
        }
    }
    

    return ans;
}
