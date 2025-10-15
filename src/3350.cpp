#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int result = 0;
        int last = 0;
        int current = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                ++current;
            }
            else
            {
                result = max(result, current / 2);
                result = max(result, min(current, last));
                last = current;
                current = 1;
            }
        }
        result = max(result, current / 2);
        result = max(result, min(current, last));

        return result;
    }
};
