#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr int MOD = 1000000007;
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int left_i = size - 1;
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] > target / 2)
            {
                left_i = i - 1;
                break;
            }
        }

        int result = 0;
        int temp = 1;
        int right_i = left_i + 1;
        while (left_i >= 0)
        {
            int left = nums[left_i];
            while (right_i < size && left + nums[right_i] <= target)
            {
                ++right_i;
                temp *= 2;
                temp %= MOD;
            }

            result += temp;
            result %= MOD;

            --left_i;
            temp *= 2;
            temp %= MOD;
        }

        return result;
    }
};