#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int minOperations(string s, int k)
    {
        int count_0 = 0;
        int count_1 = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                ++count_0;
            }
            else
            {
                ++count_1;
            }
        }

        if (count_0 == 0)
        {
            return 0;
        }
        else if (count_0 == k)
        {
            return 1;
        }
        else if (k == count_0 + count_1)
        {
            return -1;
        }
        else if (k % 2 == 0 && count_0 % 2 == 1)
        {
            return -1;
        }

        int turn_2 = min(k * 2, (count_0 + count_1 - k) * 2);

        if (k % 2 == 0)
        {
            int result_1 = 2 * ((count_0 + turn_2 - 1) / turn_2);
            int result_2 = 2 * ((abs(count_0 - k) + turn_2 - 1) / turn_2) + 1;
            return min(result_1, result_2);
        }
        else
        {
            if (count_0 % 2 == 0)
            {
                int result_1 = 2 * ((count_0 + turn_2 - 1) / turn_2);
                return result_1;
            }
            else
            {
                int result_2 = 2 * ((abs(count_0 - k) + turn_2 - 1) / turn_2) + 1;
                return result_2;
            }
        }
    }
};
