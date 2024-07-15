class Solution {
public:

   void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

    
    int countFun(vector<int> &nums,int start,int mid,int end){
        int cnt=0;
        int right=mid+1;
        for(int i=start;i<=mid;i++){
            while(right<=end&&nums[i]>((long long)2*nums[right])) right++;
            cnt+=(right-(mid+1));
        }

        return cnt;
    }

    int divide(vector<int> &nums,int start,int end){
        int cnt=0;
        if(start>=end) return cnt;
        int mid=(start+end)/2;
        cnt+=divide(nums,start,mid);
        cnt+=divide(nums,mid+1,end);
        cnt+=countFun(nums,start,mid,end);
        merge(nums,start,mid,end);
        return cnt;

    }

    int reversePairs(vector<int>& nums) {
        return divide(nums,0,nums.size()-1);
    }
};