#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool partitionArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % k)
        {
            return false;
        }
        int g = n / k;

        if (n > 10000)
        {
            // unordered_map<int, int> counts;
            int max_num = *max_element(nums.begin(), nums.end());
            int min_num = *min_element(nums.begin(), nums.end());
            vector<int> counts(max_num - min_num + 1, 0);
            for (int num : nums)
            {
                int count = ++counts[num - min_num];
                if (count > g)
                {
                    return false;
                }
            }
        }
        else
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i + g < n; ++i)
            {
                if (nums[i] == nums[i + g])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
