#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int result = 0;
        int count = 0;
        int max_num = 0;
        for (int num : nums)
        {
            if (num > max_num)
            {
                max_num = num;
                count = 1;
                result = 1;
            }
            else if (num == max_num)
            {
                ++count;
                result = max(result, count);
            }
            else
            {
                count = 0;
            }
        }
        return result;
    }
};
