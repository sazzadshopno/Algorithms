class Solution
{
public:
    string getHappyString(int n, int k)
    {
        vector<string> result;
        vector<char> letters = {'a', 'b', 'c'};
        function<void(string)> helper = [&](string curr) {
            if (result.size() == k)
                return;
            if (curr.size() == n)
            {
                result.push_back(curr);
                return;
            }
            for (int i = 0; i < letters.size(); i++)
            {
                if (curr.size() == 0 || curr.back() != letters[i])
                {
                    curr += letters[i];
                    helper(curr);
                    curr.pop_back();
                }
            }
        };
        helper("");
        return result.size() == k ? result.back() : "";
    }
};