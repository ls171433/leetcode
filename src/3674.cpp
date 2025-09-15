#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        for (int num : nums)
        {
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        if (max_num == min_num)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};
