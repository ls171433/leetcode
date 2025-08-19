#include <vector>

using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long result = 0;
        long long current = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                ++current;
            }
            else
            {
                result += (current * (current + 1)) / 2;
                current = 0;
            }
        }
        result += (current * (current + 1)) / 2;
        return result;
    }
};
