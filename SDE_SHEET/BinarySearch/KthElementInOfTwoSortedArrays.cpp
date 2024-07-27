int kthElement(int nums1[], int nums2[], int n, int m, int k)
{
    // Ensure nums1 is the smaller array
    if (n > m) return kthElement(nums2, nums1, m, n, k);
    
    int n1 = n;
    int n2 = m;
    int low = max(0, k - n2);
    int high = min(k, n);

    // Binary search on the smaller array
    while (low <= high) {
        int cut1 = (low + high) / 2; // Partition for nums1
        int cut2 = k - cut1; // Partition for nums2

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        // Check if the partition is correct
        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return 0;
}
