class Solution
{
public:
    int partitionDisjoint(vector<int> &A)
    {
        int n = A.size(), res = 1, mn = A[0], emn = A[0], extra = 0;
        for (int i = 1; i < n; ++i)
        {
            if (mn > A[i])
            {
                mn = max(mn, emn);
                res += (1 + extra);
                extra = 0;
            }
            else
            {
                extra++;
                emn = max(emn, A[i]);
            }
        }
        return res;
    }
};