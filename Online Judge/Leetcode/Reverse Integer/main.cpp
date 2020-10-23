class Solution
{
public:
    int reverse(int x)
    {
        int res;
        string s = to_string(x);
        bool minus = (s[0] == '-');
        if (minus)
            s.erase(s.begin());
        ::reverse(s.begin(), s.end());
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                idx++;
            else
                break;
        }
        if (idx == s.size())
            return 0;
        s = s.substr(idx);
        try
        {
            res = minus ? -1 * stoi(s) : stoi(s);
        }
        catch (std::out_of_range &e)
        {
            return 0;
        }
        return res;
    }
};