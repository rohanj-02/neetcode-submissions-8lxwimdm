class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> prefixMax(h.size(), 0), suffixMax(h.size(), 0);
        int ans = 0;
        for (int i = 1; i < h.size(); i++) {
            prefixMax[i] = max(prefixMax[i-1], h[i-1]);
        }
        for (int i = h.size() - 2; i > 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], h[i+1]);
        }
        for (int i = 0; i < h.size(); i++) {
            ans += max(min(prefixMax[i], suffixMax[i]) - h[i], 0);
        }
        return ans;
    }
};
