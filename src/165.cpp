#include <string>

using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int n1 = version1.size();
        int n2 = version2.size();
        int i = 0;
        int j = 0;

        while (i < n1 || j < n2)
        {
            int num1 = 0;
            for (; i < n1 && version1[i] != '.'; ++i)
            {
                num1 = num1 * 10 + (version1[i] - '0');
            }

            int num2 = 0;
            for (; j < n2 && version2[j] != '.'; ++j)
            {
                num2 = num2 * 10 + (version2[j] - '0');
            }

            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;

            ++i;
            ++j;
        }

        return 0;
    }
};
