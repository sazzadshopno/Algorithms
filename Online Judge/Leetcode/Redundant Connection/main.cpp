class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        const int MAX = 1001;
        pair<int, int> p[MAX];
        int id[MAX];
        vector<int> res;
        for (int i = 0; i < MAX; i++)
        {
            id[i] = i;
        }
        auto root = [&](int x) {
            while (id[x] != x)
            {
                id[x] = id[id[x]];
                x = id[x];
            }
            return x;
        };
        auto un = [&](int x, int y) {
            id[root(x)] = id[root(y)];
        };
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0], y = edges[i][1];
            if (root(x) != root(y))
            {
                un(x, y);
            }
            else
            {
                res = {x, y};
            }
        }
        return res;
    }
};