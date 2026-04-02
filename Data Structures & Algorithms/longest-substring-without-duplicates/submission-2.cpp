class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 1, maxAns = 1;
        unordered_set<char> currentChars;
        if (s.size() <= 1) {
            return s.size();
        }

        currentChars.insert(s[0]);
        while (r < s.size()) {
            if (currentChars.find(s[r]) == currentChars.end()) {
                currentChars.insert(s[r]);
                r++;
                maxAns = max(maxAns, (int)currentChars.size());
            } else {
                while (s[l] != s[r] && l < r) {
                    currentChars.erase(s[l]);
                    l++;
                }
                // currentChars.erase(s[l]);
                l++;r++;
            }
        }
        maxAns = max(maxAns, (int)currentChars.size());
        return maxAns;
    }
};
