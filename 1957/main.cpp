#include <string>

using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string result;
        int count = 0;
        char last = '\0';
        for (char c : s)
        {
            if (c == last)
            {
                count++;
            }
            else
            {
                count = 1;
                last = c;
            }
            if (count < 3)
            {
                result.push_back(c);
            }
        }

        return result;
    }
};
