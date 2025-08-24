#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int result = 0;
        int result_1 = 0;
        int result_2 = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                ++result_1;
                ++result_2;
                result = max(result, result_2);
            }
            else
            {
                result_2 = result_1;
                result_1 = 0;
            }
        }
        if (result == nums.size())
        {
            --result;
        }
        return result;
    }
};
