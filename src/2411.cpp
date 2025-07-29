#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<int> bits(30, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            int num = nums[i];
            int max_value = 1;
            for (int j = 0; j < 30; ++j)
            {
                if (num & (1 << j))
                {
                    bits[j] = i;
                }
                // cout << bits[j] << ' ';
                max_value = max(max_value, bits[j] - i + 1);
            }
            // cout << endl;
            result[i] = max_value;
        }
        return result;
    }
};
