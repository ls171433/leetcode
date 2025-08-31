#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (n >= m)
        {
            int dp_down = 0;
            vector<int> dp_right(m + 1, 0);
            dp_right[0] = 1;
            for (int i = 0; i < n; ++i)
            {
                dp_down = 0;
                for (int j = 0; j < m; ++j)
                {
                    if (grid[i][j])
                    {
                        swap(dp_down, dp_right[j]);
                    }
                    else
                    {
                        dp_down = (dp_down + dp_right[j]) % 1000000007;
                        dp_right[j] = dp_down;
                    }
                    // cout << i << ' ' << j << ' ' << dp_down << ' ' << dp_right[j] << endl;
                }
            }
            return dp_down;
        }
        else
        {
            int dp_right = 0;
            vector<int> dp_down(n + 1, 0);
            dp_down[0] = 1;
            for (int j = 0; j < m; ++j)
            {
                dp_right = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (grid[i][j])
                    {
                        swap(dp_right, dp_down[i]);
                    }
                    else
                    {
                        dp_right = (dp_right + dp_down[i]) % 1000000007;
                        dp_down[i] = dp_right;
                    }
                    // cout << i << ' ' << j << ' ' << dp_down[i] << ' ' << dp_right << endl;
                }
            }
            return dp_right;
        }
    }
};
