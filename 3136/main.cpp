#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
        {
            return false;
        }

        bool vowel = false;
        bool consonant = false;
        for (char c : word)
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                switch (c)
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowel = true;
                    break;
                default:
                    consonant = true;
                    break;
                }
            }
            else if (c >= '0' && c <= '9')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return vowel && consonant;
    }
};
