class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        function<void(vector<int>, int, int)> helper = [&](vector<int> t, int left, int k) {
            if (k == 0)
            {
                res.push_back(t);
                return;
            }
            for (int i = left; i <= n; i++)
            {
                t.push_back(i);
                helper(t, i + 1, k - 1);
                t.pop_back();
            }
        };
        helper({}, 1, k);
        return res;
    }
};