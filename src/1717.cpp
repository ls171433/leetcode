#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int count_1_a = 0, count_1_b = 0;
        int count_2_a = 0, count_2_b = 0;
        int score1 = 0, score2 = 0;
        int result = 0;
        for (char c : s)
        {
            if (c == 'a')
            {
                ++count_1_a;
                if (count_2_b)
                {
                    --count_2_b;
                    score2 += y;
                }
                else
                {
                    ++count_2_a;
                }
            }
            else if (c == 'b')
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
                ++count_2_b;
            }
            else
            {
                score1 += min(count_1_a, count_1_b) * y;
                score2 += min(count_2_a, count_2_b) * x;

                result += max(score1, score2);

                count_1_a = 0;
                count_1_b = 0;
                count_2_a = 0;
                count_2_b = 0;
                score1 = 0;
                score2 = 0;
            }
        }
        score1 += min(count_1_a, count_1_b) * y;
        score2 += min(count_2_a, count_2_b) * x;

        result += max(score1, score2);

        return result;
    }
};
