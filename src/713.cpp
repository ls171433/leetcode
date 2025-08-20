#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int result = 0;
        for (size_t i = 0, j = 0; i < nums.size(); ++i)
        {
            product *= nums[i];
            while (product >= k && i >= j)
            {
                product /= nums[j];
                ++j;
            }
            result += i - j + 1;
        }
        return result;
    }
};