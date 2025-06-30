#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int result = 0;
        for (int i = 0, j = 1; i < nums.size(); ++i)
        {
            while (j < nums.size() && nums[j] - nums[i] <= 1)
            {
                ++j;
            }

            if (nums[j - 1] - nums[i] == 1)
            {
                result = max(result, j - i);
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};
    cout << Solution().findLHS(nums) << endl;
    nums = {1, 1, 1, 1};
    cout << Solution().findLHS(nums) << endl;
}
