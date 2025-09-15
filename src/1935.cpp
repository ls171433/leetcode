#include <string>

using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        bool broken[26] = {false};
        for (char c : brokenLetters)
        {
            broken[c - 'a'] = true;
        }

        int result = 0;
        bool word_can_type = true;
        for (char &c : text)
        {
            if (c == ' ')
            {
                if (word_can_type)
                {
                    ++result;
                }
                word_can_type = true;
            }
            else if (broken[c - 'a'])
            {
                word_can_type = false;
            }
        }

        if (word_can_type)
        {
            ++result;
        }
        return result;
    }
};
