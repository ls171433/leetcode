#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        if (n == 3)
        {
            return values[0] * values[1] * values[2];
        }

        vector<vector<int>> memo(n, vector<int>(n, 0));

        for (int len = 2; len < n; ++len)
        {
            for (int i = 0; i + len < n; ++i)
            {
                int j = i + len;
                memo[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                {
                    memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }

        return memo[0][n - 1];
    }
};
