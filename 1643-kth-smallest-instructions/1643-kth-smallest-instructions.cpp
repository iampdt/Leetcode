class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int rows = destination[0], cols = destination[1];
        int totalSteps = rows + cols;
        vector<vector<int>> comb(totalSteps + 1, vector<int>(totalSteps + 1, 0));
        for (int i = 0; i <= totalSteps; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
        string result;
        int remainingDown = rows, remainingRight = cols;
        for (int step = 0; step < totalSteps; step++) {
            if (remainingRight > 0) {
                int pathsWithH = comb[remainingDown + remainingRight - 1][remainingDown];
                if (k <= pathsWithH) {
                    result += 'H';
                    remainingRight--;
                } else {
                    k -= pathsWithH;
                    result += 'V';
                    remainingDown--;
                }
            } else {
                result += 'V';
                remainingDown--;
            }
        }
        return result;
    }
};