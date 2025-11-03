#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int totalCost = 0;

        char previous = '\0';
        int maxTime = 0;
        int sumTime = 0;
        for (int i = 0; i < n; ++i)
        {
            char current = colors[i];
            int time = neededTime[i];

            if (current == previous)
            {
                sumTime += time;
                maxTime = max(maxTime, time);
            }
            else
            {
                totalCost += (sumTime - maxTime);

                previous = current;
                sumTime = time;
                maxTime = time;
            }
        }
        totalCost += (sumTime - maxTime);

        return totalCost;
    }
};
