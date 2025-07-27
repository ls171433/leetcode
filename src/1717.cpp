#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        char a = 'a', b = 'b';
        if (x < y)
        {
            swap(b, a);
            swap(x, y);
        }
        int count_1_a = 0, count_1_b = 0;
        int score1 = 0;
        for (char c : s)
        {
            if (c == a)
            {
                ++count_1_a;
            }
            else if (c == b)
            {
                if (count_1_a)
                {
                    --count_1_a;
                    score1 += x;
                }
                else
                {
                    ++count_1_b;
                }
            }
            else
            {
                score1 += min(count_1_a, count_1_b) * y;

                count_1_a = 0;
                count_1_b = 0;
            }
        }
        score1 += min(count_1_a, count_1_b) * y;

        return score1;
    }
};
