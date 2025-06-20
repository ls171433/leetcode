#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int count_N = 0;
        int count_S = 0;
        int count_E = 0;
        int count_W = 0;
        int max = 0;
        for (char c : s)
        {
            switch (c)
            {
            case 'N':
                ++count_N;
                break;
            case 'S':
                ++count_S;
                break;
            case 'E':
                ++count_E;
                break;
            case 'W':
                ++count_W;
                break;
            default:
                break;
            }

            int current_change = min(count_N, count_S) + min(count_E, count_W);
            if (current_change > k)
            {
                current_change = k;
            }
            int current_max_dist = abs(count_N - count_S) + abs(count_E - count_W) + 2 * current_change;
            if (current_max_dist > max)
            {
                max = current_max_dist;
            }
        }
        return max;
    }
};