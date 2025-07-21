#include <string>

using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int result = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (word[i] == word[i - 1])
            {
                ++result;
            }
        }
        return result;
    }
};