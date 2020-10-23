class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        vector<int> path = {0};
        function<void(int, int, vector<int>)> helper = [&](int source, int target, vector<int> path) {
            if (source == target)
            {
                result.push_back(path);
                return;
            }
            for (int curr : graph[source])
            {
                path.push_back(curr);
                helper(curr, target, path);
                path.erase(path.begin() + (path.size() - 1));
            }
        };
        helper(0, graph.size() - 1, path);
        return result;
    }
};