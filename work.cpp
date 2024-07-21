#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int minimumChanges(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> changeCount(k + 1, 0);  // To count changes for each possible X from 0 to k
    
    for (int i = 0; i < n / 2; ++i) {
        int a = nums[i];
        int b = nums[n - i - 1];
        
        for (int x = 0; x <= k; ++x) {
            int currentChanges = 0;
            if (abs(a - b) != x) {
                // Calculate changes needed to make abs(a - b) equal to x
                if (a != b + x && a != b - x) currentChanges++;
                if (b != a + x && b != a - x) currentChanges++;
            }
            changeCount[x] += currentChanges;
        }
    }
    
    int minChanges = *min_element(changeCount.begin(), changeCount.end());
    return minChanges;
}

// Example usage
#include <iostream>
int main() {
    vector<int> nums = {6, 3, 6, 6, 6, 3};
    int k = 6;
    cout << minimumChanges(nums, k) << endl; // Output should be 3
    return 0;
}
