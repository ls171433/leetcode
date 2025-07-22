#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int result = 0;
        int sum = 0;
        unordered_set<int> used_nums;
        for (int left = 0, right = 0; right < nums.size(); ++right)
        {
            int num_right = nums[right];
            if (used_nums.count(num_right) > 0)
            {
                int num_left = nums[left];
                while (num_left != num_right)
                {
                    used_nums.erase(num_left);
                    sum -= num_left;
                    ++left;
                    num_left = nums[left];
                }
                ++left;
            }
            else
            {
                used_nums.insert(num_right);
                sum += num_right;
            }
            result = max(result, sum);
        }
        return result;
    }
};
