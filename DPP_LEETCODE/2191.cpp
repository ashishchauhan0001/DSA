class Solution {
public:
     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> m;
        vector<pair<int, int>> vec;
    
        for (int i = 0; i < mapping.size(); ++i) {
            m[i] = mapping[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            string str = to_string(nums[i]);
            int ans = 0;
            for (char c : str) {
                ans = ans * 10 + m[c - '0'];
            }
            vec.push_back({ans, nums[i]});
        }

        // by default our sort function sort the values on the basis of both the values in lex. order but here we use lamda function which helps us to sort on the first value.
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        for (int i = 0; i < vec.size(); ++i) {
            nums[i] = vec[i].second;
        }

        return nums;
    }
};