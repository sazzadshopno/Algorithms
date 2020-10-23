class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int result = 0, n = grid.size(), m = grid[0].size();
        function<int(int, int)> helper = [&](int row, int col) {
            if (grid[row][col] == 0)
                return 0;
            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            int val = grid[row][col], res = 0;
            grid[row][col] = 0;
            for (pair<int, int> dir : dirs)
            {
                int i = row + dir.first, j = col + dir.second;
                if ((i >= 0 && i < n) && (j >= 0 && j < m))
                {
                    res = max(res, val + helper(i, j));
                }
            }
            grid[row][col] = val;
            return res;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result = max(result, helper(i, j));
            }
        }
        return result;
    }
};