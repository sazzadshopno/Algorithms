class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<int> hours = {1, 2, 4, 8}, minutes = {1, 2, 4, 8, 16, 32};
        vector<string> result;
        int x = hours.size() + minutes.size(), y = hours.size(), z = minutes.size();
        function<void(pair<int, int>, int, int)> helper = [&](pair<int, int> time, int n, int s) {
            if (n == 0)
            {
                result.push_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
                return;
            }
            for (int i = s; i < x; i++)
            {
                if (i < y)
                {
                    time.first += hours[i];
                    if (time.first < 12)
                        helper(time, n - 1, i + 1);
                    time.first -= hours[i];
                }
                else
                {
                    time.second += minutes[i - y];
                    if (time.second < 60)
                        helper(time, n - 1, i + 1);
                    time.second -= minutes[i - y];
                }
            }
        };
        helper({0, 0}, num, 0);
        return result;
    }
};