#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> all, to_a, to_b, a, b;
        for(int i = 0; i < graph.size(); ++i)
        {
            all.insert(i);
        }

        while(!all.empty() || !to_a.empty() || !to_b.empty())
        {
            if (!to_a.empty())
            {
                auto it = to_a.begin();
                int current = *it;
                to_a.erase(it);

                a.insert(current);
                all.erase(current);

                for (int next: graph[current])
                {
                    if (a.find(next) != a.end())
                    {
                        return false;
                    }

                    if (b.find(next) == b.end())
                    {
                        to_b.insert(next);
                    }
                }
            }
            else if (!to_b.empty())
            {
                auto it = to_b.begin();
                int current = *it;
                to_b.erase(it);

                b.insert(current);
                all.erase(current);

                for (int next: graph[current])
                {
                    if (b.find(next) != b.end())
                    {
                        return false;
                    }

                    if (a.find(next) == a.end())
                    {
                        to_a.insert(next);
                    }
                }
            }
            else if (!all.empty())
            {
                auto it = all.begin();
                int current = *it;
                all.erase(it);

                a.insert(current);

                for (int next: graph[current])
                {
                    if (b.find(next) == b.end())
                    {
                        to_b.insert(next);
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> graph = {{1}, {0}, {3}, {2}};
    auto result = Solution().isBipartite(graph);
    cout << result << endl;
}
