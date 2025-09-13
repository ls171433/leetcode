#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> count(26, 0);
        for (char c : s)
        {
            ++count[c - 'a'];
        }

        int max_v = 0;
        int max_c = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (i == 'a' - 'a' ||
                i == 'e' - 'a' ||
                i == 'i' - 'a' ||
                i == 'o' - 'a' ||
                i == 'u' - 'a')
            {
                max_v = max(max_v, count[i]);
            }
            else
            {
                max_c = max(max_c, count[i]);
            }
        }
        return max_v + max_c;
    }
};
