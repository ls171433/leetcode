#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int score(vector<string> &cards, char x)
    {
        int count_aa = 0;
        int count_ax['j' - 'a' + 1] = {0};
        int count_xa['j' - 'a' + 1] = {0};
        int count_am = 0;
        int count_ma = 0;
        int count_ar = 0;
        int count_ra = 0;
        for (const auto &card : cards)
        {
            if (card[0] == x)
            {
                if (card[1] == x)
                {
                    ++count_aa;
                }
                else
                {
                    ++count_ax[card[1] - 'a'];
                }
            }
            else
            {
                if (card[1] == x)
                {
                    ++count_xa[card[0] - 'a'];
                }
            }
        }
        for (int i = 0; i < 'j' - 'a' + 1; ++i)
        {
            count_am = max(count_am, count_ax[i]);
            count_ma = max(count_ma, count_xa[i]);
            count_ar += count_ax[i];
            count_ra += count_xa[i];
        }
        count_ar -= count_am;
        count_ra -= count_ma;

        if (count_aa > count_am + count_ar + count_ma + count_ra)
        {
            return count_am + count_ar + count_ma + count_ra;
        }
        else if (count_aa < count_am - count_ar + count_ma - count_ra)
        {
            return count_aa + count_ar + count_ra;
        }
        else if (count_aa > 0 || (count_am + count_ar) % 2 == 0 || (count_ma + count_ra) % 2 == 0)
        {
            return (count_aa + count_am + count_ar + count_ma + count_ra) / 2;
        }
        else
        {
            return (count_am + count_ar) / 2 + (count_ma + count_ra) / 2;
        }
    }
};
