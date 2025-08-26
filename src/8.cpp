#include <string>

using namespace std;

class Solution
{
public:
    enum class State
    {
        START,
        NUMBER,
        END,
    };

    int myAtoi(string s)
    {
        State state = State::START;
        int sign = 1;
        long long result = 0;
        for (char c : s)
        {
            switch (state)
            {
            case State::START:
                if (c == ' ')
                {
                    continue;
                }
                else if (c == '+')
                {
                    sign = 1;
                    state = State::NUMBER;
                    continue;
                }
                else if (c == '-')
                {
                    sign = -1;
                    state = State::NUMBER;
                    continue;
                }
                state = State::NUMBER;
            case State::NUMBER:
                if (c >= '0' && c <= '9')
                {
                    result *= 10;
                    result += c - '0';
                    if (sign == 1 && result > INT_MAX)
                    {
                        return INT_MAX;
                    }
                    else if (sign == -1 && -result < INT_MIN)
                    {
                        return INT_MIN;
                    }
                    continue;
                }
                state = State::END;
                goto end;
            default:
                state = State::END;
                goto end;
            }
        }
    end:
        return sign * result;
    }
};
