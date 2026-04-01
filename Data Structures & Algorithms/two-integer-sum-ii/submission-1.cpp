class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,0);
        int l = 0, r = numbers.size() - 1;
        int sum;
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) {
                ans[0] = l+1;
                ans[1] = r+1;
                break;
            }
            if (sum < target) {
                l++;
            }
            if (sum > target) {
                r--;
            }
        }
        return ans;

    }
};
