#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> result(n, 1);
        unordered_map<int, int> lake_last_dry_days;
        set<int> dry_days;

        for (int i = 0; i < n; i++)
        {
            if (rains[i] > 0)
            {
                int lake_id = rains[i];
                auto lake_it = lake_last_dry_days.find(lake_id);
                if (lake_it != lake_last_dry_days.end())
                {
                    int last_dry_day = lake_it->second;
                    auto it = dry_days.lower_bound(last_dry_day);
                    if (it == dry_days.end())
                    {
                        return {};
                    }
                    int dry_day = *it;
                    result[dry_day] = lake_id;
                    dry_days.erase(it);
                    lake_it->second = i;
                }
                else
                {
                    lake_last_dry_days.insert(lake_id, i);
                }
                result[i] = -1;
            }
            else
            {
                dry_days.insert(i);
            }
        }

        return result;
    }
};
