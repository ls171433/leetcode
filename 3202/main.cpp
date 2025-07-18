#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        vector<vector<int>> table(k, vector<int>(k, 0));
        int result;
        for (int num : nums)
        {
            num %= k;
            for (int num2 = 0; num2 < k; ++num2)
            {
                int new_result = table[num2][num] + 1;
                table[num][num2] = new_result;
                result = max(result, new_result);
            }
        }

        return result;
    }
};
