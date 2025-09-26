#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 2; i < nums.size(); ++i)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    result += right - left;
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }
        return result;
    }
};
