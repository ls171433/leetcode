#include <vector>

using namespace std;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int current_sum = 0;
        int max_sum = 0;

        int i = 0;
        while (i < fruits.size() && fruits[i][0] < startPos - k)
        {
            ++i;
        }

        int j = i;
        while (j < fruits.size() &&
               fruits[j][0] <= startPos + k &&
               fruits[j][0] - fruits[i][0] + min(fruits[j][0] - startPos, startPos - fruits[i][0]) <= k)
        {
            current_sum += fruits[j][1];
            max_sum = max(max_sum, current_sum);
            ++j;
        }

        while (i < fruits.size() && fruits[i][0] <= startPos)
        {
            current_sum -= fruits[i][1];
            ++i;

            while (j < fruits.size() &&
                   fruits[j][0] <= startPos + k &&
                   fruits[j][0] - fruits[i][0] + min(fruits[j][0] - startPos, startPos - fruits[i][0]) <= k)
            {
                current_sum += fruits[j][1];
                max_sum = max(max_sum, current_sum);
                ++j;
            }

            if (j == fruits.size() || fruits[j][0] > startPos + k)
            {
                break;
            }
        }

        return max_sum;
    }
};
