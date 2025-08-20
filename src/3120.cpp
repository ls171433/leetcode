#include <string>

using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        bool upper[26] = {};
        bool lower[26] = {};
        for (const auto &c : word)
        {
            if (c >= 'a' && c <= 'z')
            {
                lower[c - 'a'] = true;
            }
            else
            {
                upper[c - 'A'] = true;
            }
        }
        int count = 0;
        for (size_t i = 0; i < 26; ++i)
        {
            if (lower[i] && upper[i])
            {
                ++count;
            }
        }
        return count;
    }
};