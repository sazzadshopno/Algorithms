class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] > 0)
                    break;
                if (left > i + 1 && nums[left] == nums[left - 1])
                {
                    left += 1;
                    continue;
                }
                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left += 1;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right -= 1;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left += 1, right -= 1;
                }
            }
        }
        return res;
    }
};