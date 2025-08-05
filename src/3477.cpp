#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        map<int, int, greater<int>> least_position;

        int result = 0;
        for (int fruit : fruits)
        {
            int i_begin = 0;
            auto it = least_position.lower_bound(fruit);
            if (it != least_position.end())
            {
                i_begin = (it->second);
            }

            signed char failed = 1;
            for (int i = i_begin; i < n; ++i)
            {
                if (baskets[i] >= fruit)
                {
                    failed = 0;
                    baskets[i] = 0;
                    least_position[fruit] = i + 1;
                    break;
                }
            }
            result += failed;
        }

        return result;
    }
};
