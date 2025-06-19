#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        set<int> cities;
        for (int i = 0; i < n; ++i)
        {
            cities.insert(i);
        }

        vector<int> result;
        result.reserve(queries.size());

        for (const auto &query : queries)
        {
            cities.erase(cities.upper_bound(query[0]), cities.lower_bound(query[1]));
            result.push_back(cities.size() - 1);
        }

        return result;
    }
};