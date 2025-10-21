#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = 0;

        int previous_num = nums[0] - 1;
        int i_p_upper = 0;
        int i_0_upper = 0;
        int i_0_lower = 0;
        int i_m_upper = 0;
        int i_m_lower = 0;
        int i_mm_lower = 0;

        for (int i = 0, j = 0; i < n; i = j)
        {
            int num = nums[i];
            if (previous_num == num)
            {
                continue;
            }
            previous_num = num;

            i_0_lower = i;

            while (i_mm_lower < n && nums[i_mm_lower] < num - k - k)
            {
                ++i_mm_lower;
            }

            i_m_lower = max(i_m_lower, i_mm_lower);
            while (i_m_lower < n && nums[i_m_lower] < num - k)
            {
                ++i_m_lower;
            }

            i_m_upper = i_m_lower;
            while (i_m_upper < n && nums[i_m_upper] <= num - k)
            {
                ++i_m_upper;
            }

            i_0_upper = i + 1;
            while (i_0_upper < n && nums[i_0_upper] <= num)
            {
                ++i_0_upper;
            }
            j = i_0_upper;

            i_p_upper = max(i_p_upper, i_0_upper);
            while (i_p_upper < n && nums[i_p_upper] <= num + k)
            {
                ++i_p_upper;
            }

            int distance_0 = i_0_upper - i_0_lower;
            int result_0 = distance_0 + min<int>(i_p_upper - i_m_lower - distance_0, numOperations);
            // cout << num << ' ' << result_0 << endl;
            result = max<int>(result, result_0);

            int distance_m = i_m_upper - i_m_lower;
            if (distance_m == 0)
            {
                int result_m = distance_m + min<int>(i_0_upper - i_mm_lower, numOperations);
                // cout << num - k << ' ' << result_m << endl;
                result = max<int>(result, result_m);
            }
        }

        return result;
    }
};
