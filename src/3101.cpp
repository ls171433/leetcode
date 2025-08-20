#include <vector>

using namespace std;

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long result = nums.size();
        long long count = 0;
        for (long long i = 0; i + 1 < nums.size(); ++i)
        {
            if (nums[i] != nums[i + 1])
            {
                ++count;
            }
            else
            {
                result += count * (count + 1) / 2;
                count = 0;
            }
        }
        result += count * (count + 1) / 2;
        return result;
    }
};
