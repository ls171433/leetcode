#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        path(result, graph, 0, vector<int>{});
        return result;
    }

    static void path(vector<vector<int>> &result, const vector<vector<int>> &graph, int from, vector<int> current_path)
    {
        current_path.push_back(from);
        if (from == graph.size() - 1)
        {
            result.push_back(current_path);
        }

        const vector<int> &to_list = graph[from];
        for (int to : to_list)
        {
            path(result, graph, to, current_path);
        }
    }
};

int main()
{
    vector<vector<int>> graph;
    graph.push_back({1, 2});
    graph.push_back({3});
    graph.push_back({3});
    graph.push_back({});
    vector<vector<int>> result = Solution{}.allPathsSourceTarget(graph);
    for (const auto &route : result)
    {
        for (const auto &value : route)
        {
            cout << value << ' ';
        }
        cout << endl;
    }
}