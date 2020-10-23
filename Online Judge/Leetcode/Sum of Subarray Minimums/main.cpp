class Solution
{
public:
    int sumSubarrayMins(vector<int> &A)
    {
        int mod = 1e9 + 7, res = 0, n = A.size();
        stack<int> s;
        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && A[s.top()] > (i == n ? 0 : A[i]))
            {
                int j = s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                res = (res + A[j] * (i - j) * (j - k)) % mod;
            }
            s.push(i);
        }
        return res;
    }
};