class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr, int k = 0)
    {
        if (k == arr.size())
            return 0;
        int mx = arr[k];
        for (int i = k; i <= mx; i++)
        {
            mx = max(mx, arr[i]);
        }
        return maxChunksToSorted(arr, mx + 1) + 1;
    }
};