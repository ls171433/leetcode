#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int odd = 0;
        int even = 0;
        int interlace = 1;
        int interlace_mark = nums[0];
        for (int num : nums)
        {
            odd += num % 2;
            even += (num + 1) % 2;
            interlace += (num + interlace_mark) % 2;
            interlace_mark = num;
        }
        return max(max(odd, even), interlace);
    }
};
