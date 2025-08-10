class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int ySwapRow = x + k - 1;
        if (k % 2 == 0) {
            for (int i = x; i <= x + ((k - 1) / 2); i++) {
                if (!ySwapRow)
                    break;
                for (int j = y; j < y + k; j++) {
                    int temp = grid[i][j];
                    grid[i][j] = grid[ySwapRow][j];
                    grid[ySwapRow][j] = temp;
                }
                ySwapRow--;
            }
        } else {
            for (int i = x; i <= x + (k / 2); i++) {
                if (!ySwapRow)
                    break;
                for (int j = y; j < y + k; j++) {
                    int temp = grid[i][j];
                    grid[i][j] = grid[ySwapRow][j];
                    grid[ySwapRow][j] = temp;
                }
                ySwapRow--;
            }
        }
        return grid;
    }
};©leetcode
