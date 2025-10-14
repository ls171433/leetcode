#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        if (k == 1 && nums.size() >= 2)
        {
            return true;
        }

        // 0: finding first
        // 1: found first
        // 2: finding second
        int status = 0;
        int current = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                ++current;
                if (current >= 2 * k)
                {
                    return true;
                }
                else if (status == 2 && current >= k)
                {
                    return true;
                }
                else if (status == 0 && current >= k)
                {
                    status = 1;
                }
            }
            else
            {
                if (status == 1)
                {
                    status = 2;
                }
                else
                {
                    status = 0;
                }
                current = 1;
            }

            // cout << i << ' ' << status << ' ' << current << endl;
        }

        return false;
    }
};
