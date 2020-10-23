class Solution
{
public:
    vector<int> intersect(vector<int> &a, vector<int> &b)
    {
        map<int, int> mp;
        vector<int> res;
        for (int i : a)
            mp[i]++;
        for (int i : b)
        {
            if (mp[i])
            {
                res.push_back(i);
                mp[i]--;
            }
        }
        return res;
    }
};