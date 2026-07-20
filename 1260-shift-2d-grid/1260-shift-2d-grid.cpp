class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total_size = m * n;
        k %= total_size;
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                int opos = i * n + j;
                int npos = (opos + k) % total_size;
                int n_row = npos / n;
                int n_col = npos % n;
                result[n_row][n_col] = grid[i][j];
            }
        }
        return result;
    }
};