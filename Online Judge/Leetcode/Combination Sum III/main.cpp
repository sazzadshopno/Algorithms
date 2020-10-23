class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        function<void(vector<int>, int)> helper = [&](vector<int> sol, int sum) {
            if (sol.size() == k && sum == 0)
            {
                res.push_back(sol);
                return;
            }
            if (sol.size() < k)
            {
                for (int i = sol.empty() ? 1 : sol.back() + 1; i < 10; i++)
                {
                    if (sum - i < 0)
                        break;
                    sol.push_back(i);
                    helper(sol, sum - i);
                    sol.pop_back();
                }
            }
        };
        helper({}, n);
        return res;
    }
};