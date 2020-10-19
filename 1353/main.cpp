#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), compare);

        int count = 0;
        int current_day = events.front()[0] - 1;
        multiset<int> end_times;
        auto it = events.cbegin();

        while (true)
        {
            if (end_times.empty() && it == events.end())
            {
                break;
            }
            else if (end_times.empty())
            {
                end_times.insert((*it)[1]);
                current_day = (*it)[0] - 1;
                ++it;
                continue;
            }
            else if (it == events.end())
            {
                ++current_day;
                ++count;
                end_times.erase(end_times.begin());

                while (!end_times.empty() && *(end_times.begin()) <= current_day)
                {
                    end_times.erase(end_times.begin());
                }

                continue;
            }
            else if (current_day + 1 < (*it)[0])
            {
                ++current_day;
                ++count;
                end_times.erase(end_times.begin());

                while (!end_times.empty() && *(end_times.begin()) <= current_day)
                {
                    end_times.erase(end_times.begin());
                }

                continue;
            }
            else
            {
                end_times.insert((*it)[1]);
                ++it;
                continue;
            }
        }

        return count;
    }

    static bool
    compare(const vector<int> &l, const vector<int> &r)
    {
        if (l[0] < r[0])
        {
            return true;
        }
        else if (l[0] > r[0])
        {
            return false;
        }
        else if (l[1] < r[1])
        {
            return true;
        }
        else if (l[1] > r[1])
        {
            return false;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<vector<int>> events{{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    auto result = Solution().maxEvents(events);
    cout << result << endl;
}
