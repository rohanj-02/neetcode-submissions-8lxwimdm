class Solution {
public:

    bool isValidBox(int boxNumber, vector<vector<char>>& board) {
        unordered_map<int, int> freqMap;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                int x_i = ((boxNumber-1)/3) * 3 + i, y_i = ((boxNumber-1)%3)*3 + j;
                if (board[x_i-1][y_i-1] != '.')
                    freqMap[board[x_i-1][y_i-1]-'0']++;
            }
        }
        return isValidFrequencyMap(freqMap);
    }

    bool isValidFrequencyMap(unordered_map<int, int>& freq) {
        for (int i = 1; i <= 9; i++) {
            if (freq[i] > 1) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;

        // check rows
        for (int i = 0; i < 9; i++) {
            unordered_map<int, int> freqMap;
            
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    freqMap[board[i][j] - '0']++;
            }
            isValid = isValid && isValidFrequencyMap(freqMap);
        }

        for (int i = 0; i < 9; i++) {
            unordered_map<int, int> freqMap;
            
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.')
                    freqMap[board[j][i] - '0']++;
            }
            isValid = isValid && isValidFrequencyMap(freqMap);
        }

        for(int i = 1; i <= 9; i++) {
            isValid = isValid && isValidBox(i, board);
        }
        return isValid;
    }
};