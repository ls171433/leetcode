#include <vector>

using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<int> dp(forget, 0);
        dp[0] = 1;

        long long new_person = 0;
        for (int i = 1; i < n; ++i)
        {
            new_person += 1000000007;
            new_person -= dp[i % forget];
            new_person += dp[(i + forget - delay) % forget];
            new_person %= 1000000007;
            dp[i % forget] = new_person;
        }

        long long result = 0;
        for (int j = 0; j < forget; ++j)
        {
            result += dp[j];
        }

        return result % 1000000007;
    }
};
