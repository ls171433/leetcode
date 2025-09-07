#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long bowlSubarrays(vector<int> &nums)
    {
        vector<int> left_edges;
        if (nums[0] > nums[1])
        {
            left_edges.push_back(nums[0]);
        }
        int prev = nums[1];

        int result = 0;
        for (int i = 2; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (num > prev)
            {
                while (!left_edges.empty() && left_edges.back() < num)
                {
                    left_edges.pop_back();
                    ++result;
                }
                if (!left_edges.empty())
                {
                    ++result;
                }
            }
            else
            {
                left_edges.push_back(prev);
            }
            prev = num;
            // cout << left_edges.size() << endl;
        }
        return result;
    }
};
