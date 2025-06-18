#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        vector<vector<int>> result;
        result.reserve(nums.size() / 3);

        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
            {
                return {};
            }
            result.emplace_back(vector<int>{nums[i], nums[i + 1], nums[i + 2]});
        }
        return result;
    }
};