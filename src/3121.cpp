#include <string>

using namespace std;

enum state
{
    NONE,
    LOWER,
    UPPER,
    LOWER_UPPER,
    LOWER_UPPER_LOWER,
};

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        state curr_state[26] = {};
        for (const auto &c : word)
        {
            if (c >= 'a' && c <= 'z')
            {
                state &curr_c_state = curr_state[c - 'a'];
                switch (curr_c_state)
                {
                case NONE:
                    curr_c_state = LOWER;
                    break;
                case LOWER_UPPER:
                    curr_c_state = LOWER_UPPER_LOWER;
                    break;
                default:
                    break;
                }
            }
            else
            {
                state &curr_c_state = curr_state[c - 'A'];
                switch (curr_c_state)
                {
                case NONE:
                    curr_c_state = UPPER;
                    break;
                case LOWER:
                    curr_c_state = LOWER_UPPER;
                    break;
                default:
                    break;
                }
            }
        }
        int count = 0;
        for (const auto &state : curr_state)
        {
            if (state == LOWER_UPPER)
            {
                ++count;
            }
        }
        return count;
    }
};