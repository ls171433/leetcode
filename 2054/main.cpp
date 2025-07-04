#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [](const vector<int> &left, const vector<int> &right)
             { return left[0] != right[0] ? left[0] > right[0] : left[2] > right[2]; });

        map<int, int> right_maxes;
        int right_max = 0;
        for (const auto &event : events)
        {
            if (event[2] > right_max)
            {
                right_maxes.insert(std::make_pair(event[0], event[2]));
                right_max = event[2];
            }
        }

        int result = 0;
        for (const auto &event : events)
        {
            auto it = right_maxes.upper_bound(event[1]);
            if (it != right_maxes.end())
            {
                result = max(result, event[2] + it->second);
            }
            else
            {
                result = max(result, event[2]);
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    cout << Solution().maxTwoEvents(events) << endl;
    events = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}};
    cout << Solution().maxTwoEvents(events) << endl;
    events = {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}};
    cout << Solution().maxTwoEvents(events) << endl;
}
