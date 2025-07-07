#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> my_queue;

        int day = 0;
        int i = 0;
        int n = events.size();
        int count = 0;
        while (i < n || !my_queue.empty())
        {
            if (my_queue.empty())
            {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day)
            {
                my_queue.push(events[i][1]);
                ++i;
            }
            my_queue.pop();
            ++count;
            ++day;
            while (!my_queue.empty() && my_queue.top() < day)
            {
                my_queue.pop();
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> events{{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    auto result = Solution().maxEvents(events);
    cout << result << endl;
}
