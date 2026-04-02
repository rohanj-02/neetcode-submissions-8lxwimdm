class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int> prefixMin(p.size(), 0), suffixMax(p.size(), 0);
        int ans = 0;
        prefixMin[0] = p[0];
        for (int i = 1; i < p.size(); i++) {
            prefixMin[i] = min(p[i], prefixMin[i-1]);
        }
        suffixMax[p.size()-1] = p[p.size()-1];
        for (int i = p.size() - 2; i > 0; i--) {
            suffixMax[i] = max(p[i], suffixMax[i+1]);
        }

        for (int i = 0; i < p.size(); i++) {
            ans = max(ans, suffixMax[i] - prefixMin[i]);
        }

        return ans;
    }
};
