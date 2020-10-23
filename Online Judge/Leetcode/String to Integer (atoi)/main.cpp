class Solution
{
public:
    int myAtoi(string s)
    {
        int a;
        stringstream ss(s);
        ss >> s;
        try
        {
            a = stoi(s);
        }
        catch (std::invalid_argument &e)
        {
            return 0;
        }
        catch (std::out_of_range &e)
        {
            if (s[0] == '-')
                return INT_MIN;
            else
                return INT_MAX;
        }
        return a;
    }
};