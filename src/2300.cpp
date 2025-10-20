#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> result;
        result.reserve(spells.size());

        sort(potions.begin(), potions.end());
        for (int spell : spells)
        {
            long long min_potion = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), min_potion);
            result.push_back(distance(it, potions.end()));
        }
        return result;
    }
};
