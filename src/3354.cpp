#include <vector>

using namespace std;

class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        int result = 0;
        int left = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                if (sum % 2 == 0 && left == sum / 2)
                {
                    result += 2;
                }
                else if (sum % 2 == 1 && (left == sum / 2 || left == sum / 2 + 1))
                {
                    result += 1;
                }
            }
            else
            {
                left += num;
            }
        }

        return result;
    }
};
