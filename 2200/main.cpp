#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size();
        int count = 0;
        vector<int> result;

        for (int i = 0; i < k; ++i)
        {
            if (nums[i] == key)
            {
                ++count;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (i + k < n && nums[i + k] == key)
            {
                ++count;
            }
            if (count)
            {
                result.push_back(i);
            }
            if (i - k >= 0 && nums[i - k] == key)
            {
                --count;
            }
        }

        return result;
    }
};