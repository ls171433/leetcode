#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> result;
        result.reserve(nums.size());
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (gcd(last, num) > 1)
            {
                last = lcm(last, num);
                while (!result.empty() && gcd(result.back(), last) > 1)
                {
                    last = lcm(result.back(), last);
                    result.pop_back();
                }
            }
            else
            {
                result.push_back(last);
                last = num;
            }
        }
        result.push_back(last);
        return result;
    }
};
