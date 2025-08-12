#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfWays(int n, int x)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1, power = 1; (power = powi(i, x)) <= n; ++i)
        {
            // cout << power << endl;
            for (int j = n; j >= power; --j)
            {
                dp[j] += dp[j - power];
                dp[j] %= MOD;
            }
        }
        // for (int i = 0; i <= n; ++i)
        // {
        //     cout << dp[i] << endl;
        // }
        return dp[n];
    }

    int powi(int base, int exp)
    {
        int result = 1;
        while (exp)
        {
            if (exp & 1)
            {
                result *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return result;
    }
};
