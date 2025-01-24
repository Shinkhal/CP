class Solution {
public:
    void recur(vector<vector<int>>& mat, int n, vector<string>& ans, string& temp, int row, int col) {
        if (row == n - 1 && col == n - 1) {
            ans.push_back(temp);
            return;
        }
        if (row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0) {
            return;
        }
        mat[row][col] = 0;
        const int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const char dirChar[4] = {'D', 'U', 'L', 'R'};

        for (int i = 0; i < 4; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            temp.push_back(dirChar[i]);
            recur(mat, n, ans, temp, newRow, newCol);
            temp.pop_back();
        }
        mat[row][col] = 1;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        string temp;
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return ans;
        }
        recur(mat, n, ans, temp, 0, 0);
        return ans;
    }
};
