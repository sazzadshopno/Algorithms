class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> temp = matrix;
        int n = matrix.size();
        for (int i = 0, t_i = 0; i < n; ++i, ++t_i)
        {
            for (int j = n - 1, t_j = 0; j > -1; --j, ++t_j)
            {
                matrix[t_i][t_j] = temp[j][i];
            }
        }
    }
};