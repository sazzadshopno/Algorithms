class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res = {};
        function<void(vector<int>, int)> helper = [&](vector<int> subset, int idx) {
            res.push_back(subset);
            for (int i = idx; i < nums.size(); i++)
            {
                subset.push_back(nums[i]);
                helper(subset, i + 1);
                subset.pop_back();
            }
            return;
        };
        helper({}, 0);
        return res;
    }
};