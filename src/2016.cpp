#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int min = nums[0];
        int result = -1;
        for (int num : nums)
        {
            if (num < min)
            {
                min = num;
            }
            if (num > min && num - min > result)
            {
                result = num - min;
            }
        }
        return result;
    }
};