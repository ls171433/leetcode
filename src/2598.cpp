#include <vector>

using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        vector<int> counts(value, 0);
        for (int num : nums)
        {
            int mod = ((num % value) + value) % value;
            ++counts[mod];
        }

        int min_mod = 0;
        int min_count = counts[0];
        for (int i = 1; i < value; ++i)
        {
            if (counts[i] < min_count)
            {
                min_count = counts[i];
                min_mod = i;
            }
        }
        int result = min_count * value + min_mod;

        return result;
    }
};
