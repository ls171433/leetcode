#include <vector>

using namespace std;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        vector<int> new_fruits(2 * k + 1, 0);
        for (auto &fruit : fruits)
        {
            int position = fruit[0];
            int amount = fruit[1];
            if (position >= startPos - k && position <= startPos + k)
            {
                new_fruits[position - startPos + k] += amount;
            }
        }

        int current_left = 0;
        int current_right = 0;
        for (int i = 0; i <= k; ++i)
        {
            current_left += new_fruits[i];
            current_right += new_fruits[2 * k - i];
        }
        int result = max(current_left, current_right);

        for (int i = 1; i <= k / 3; ++i)
        {
            current_left -= new_fruits[2 * i - 2];
            current_left -= new_fruits[2 * i - 1];
            current_left += new_fruits[k + i];
            current_right -= new_fruits[2 * k - (2 * i - 2)];
            current_right -= new_fruits[2 * k - (2 * i - 1)];
            current_right += new_fruits[k - i];
            result = max(result, max(current_left, current_right));
        }
        return result;
    }
};
