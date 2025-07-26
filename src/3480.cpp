#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        vector<int> conflict1(n + 1, n + 1);
        vector<int> conflict2(n + 1, n + 1);
        for (const auto &conflicting_pair : conflictingPairs)
        {
            int a = min(conflicting_pair[0], conflicting_pair[1]);
            int b = max(conflicting_pair[0], conflicting_pair[1]);
            if (b < conflict1[a])
            {
                conflict2[a] = conflict1[a];
                conflict1[a] = b;
            }
            else if (b < conflict2[a])
            {
                conflict2[a] = b;
            }
        }

        int conflict1_temp = n + 1;
        int conflict2_temp = n + 1;
        for (int i = n; i >= 1; --i)
        {
            if (conflict1[i] < conflict1_temp)
            {
                conflict2_temp = min(conflict2[i], conflict1_temp);
                conflict1_temp = conflict1[i];
            }
            else
            {
                conflict2_temp = min(conflict1[i], conflict2_temp);
            }
            // cout << i << ' ' << conflict1[i] << ' ' << conflict1_temp << endl;
            // cout << i << ' ' << conflict2[i] << ' ' << conflict2_temp << endl;
            conflict1[i] = conflict1_temp;
            conflict2[i] = conflict2_temp;
        }

        long long base = 0;
        for (int i = 1; i <= n; ++i)
        {
            base += conflict1[i] - i;
        }

        long long max_diff = 0;
        long long max_diff_temp = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1 || conflict1[i] == conflict1[i - 1])
            {
                max_diff_temp += conflict2[i] - conflict1[i];
            }
            else
            {
                max_diff = max(max_diff, max_diff_temp);
                max_diff_temp = conflict2[i] - conflict1[i];
            }
        }
        max_diff = max(max_diff, max_diff_temp);

        return base + max_diff;
    }
};
