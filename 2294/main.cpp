#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int result = 1;
        for (int num : nums)
        {
            if (num > min + k)
            {
                min = num;
                ++result;
            }
        }
        return result;
    }
};
