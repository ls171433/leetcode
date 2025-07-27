#include <vector>

using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int count = 0;
        int sign = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1] && sign <= 0)
            {
                ++count;
                sign = 1;
            }
            else if (nums[i] < nums[i - 1] && sign >= 0)
            {
                ++count;
                sign = -1;
            }
        }

        if (count == 0)
        {
            return 0;
        }

        return count - 1;
    }
};
