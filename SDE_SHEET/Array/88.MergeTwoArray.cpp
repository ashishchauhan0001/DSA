class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int j=m;
        int i=0;
        while(i!=n){
            nums1[j]=nums2[i];
            i++;
            j++;
        }

        sort(nums1.begin(),nums1.end());
    }
};