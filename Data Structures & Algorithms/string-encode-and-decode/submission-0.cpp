class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto str: strs) {
            encoded = encoded + to_string(str.length()) + "_" + str;
        }
        cout << encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0; 
        while (i < s.length()) {
            int s_len = 0;
            while (s[i] != '_') {
                i++;
                s_len++;
            }
            s_len = stoi(s.substr(i-s_len, s_len));
            i++;
            strs.push_back(s.substr(i, s_len));
            i+= s_len;
        }
        return strs;
    }
};
