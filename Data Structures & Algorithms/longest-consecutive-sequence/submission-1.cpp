class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(), nums.end());
        int max_ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (lookup.find(nums[i] - 1) == lookup.end()) {
                int min_ans = 0, j = nums[i];
                while (lookup.find(j) != lookup.end()) {
                    j++;
                    min_ans++;
                }
                max_ans = max(max_ans, min_ans);
            }
        }
        return max_ans;
    }
};
