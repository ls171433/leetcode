#include <string>

using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        char max_num = '\0';
        for (int i = 0; i < num.size() - 2; ++i)
        {
            if (num[i] > max_num && num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                max_num = num[i];
            }
        }
        return max_num ? string(3, max_num) : string();
    }
};
