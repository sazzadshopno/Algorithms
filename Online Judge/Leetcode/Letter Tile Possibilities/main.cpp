class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        set<string> result;
        function<void(string, string, int)> subsetsUtil = [&](string s, string subset, int idx) {
            if (subset.size() > 0)
            {
                vector<char> tempSubset;
                for (char c : subset)
                {
                    tempSubset.push_back(c);
                }
                sort(tempSubset.begin(), tempSubset.end());
                do
                {
                    string permSubset = "";
                    for (char c : tempSubset)
                    {
                        permSubset += c;
                    }
                    result.insert(permSubset);
                    ::reverse(permSubset.begin(), permSubset.end());
                    result.insert(permSubset);
                } while (next_permutation(tempSubset.begin(), tempSubset.end()));
            }
            for (int i = idx; i < s.size(); i++)
            {
                subset += s[i];
                subsetsUtil(s, subset, i + 1);
                subset.pop_back();
            }
        };
        function<void(string)> subsets = [&](string s) {
            string subset;
            int idx = 0;
            subsetsUtil(s, subset, idx);
        };
        subsets(tiles);
        return result.size();
    }
};