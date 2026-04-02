class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minTillNow = p[0], ansTillNow = 0;
        for (int i = 1; i < p.size(); i++) {
            ansTillNow = max(ansTillNow, p[i] - minTillNow);
            minTillNow = min(minTillNow, p[i]);
        }
        return ansTillNow;
    }
};
