class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<pair<int, int>> v = {{12, 11}, {123, 111}, {1234, 1111}, {12345, 11111}, {123456, 111111}, {1234567, 1111111}, {12345678, 11111111}, {123456789, 111111111}};
        vector<int> res;
        string l = to_string(low);
        for (int i = l.size() - 2; i < v.size();)
        {
            int x = v[i].first;
            if (x > high)
                break;
            if (x < low)
            {
                if (v[i].first % 10 == 9)
                {
                    i++;
                    continue;
                }
                v[i].first += v[i].second;
                continue;
            }
            res.push_back(x);
            if (x % 10 == 9)
            {
                i++;
                continue;
            }
            v[i].first += v[i].second;
        }
        return res;
    }
};