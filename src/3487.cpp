#include <climits>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        unordered_set<int> good_nums;
        int max_bad_num = INT_MIN;
        for (int num : nums)
        {
            if (num > 0)
            {
                good_nums.insert(num);
            }
            else
            {
                max_bad_num = max(max_bad_num, num);
            }
        }

        int result = 0;
        if (!good_nums.empty())
        {
            for (int num : good_nums)
            {
                result += num;
            }
            return result;
        }
        else
        {
            return max_bad_num;
        }
    }
};
