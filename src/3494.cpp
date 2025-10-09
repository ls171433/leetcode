#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();

        vector<long long> wizard(n, 0);
        for (int j = 0; j < m; ++j)
        {
            long long mana_j = mana[j];
            long long additional_start_time = 0;
            wizard[0] += skill[0] * mana_j;
            for (int i = 1; i < n; ++i)
            {
                if (wizard[i] > wizard[i - 1])
                {
                    additional_start_time += wizard[i] - wizard[i - 1];
                    wizard[i] += skill[i] * mana_j;
                }
                else
                {
                    wizard[i] = wizard[i - 1] + skill[i] * mana_j;
                }
            }

            wizard[0] += additional_start_time;
            for (int i = 1; i < n; ++i)
            {
                wizard[i] = wizard[i - 1] + skill[i] * mana_j;
            }

            // for (int i = 0; i < n; ++i)
            // {
            //     cout << wizard[i] << endl;
            // }
        }

        return wizard[n - 1];
    }
};
