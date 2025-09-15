#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int min_row = INT_MAX;
        int max_row = INT_MIN;
        int min_col = INT_MAX;
        int max_col = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j])
                {
                    min_row = min(min_row, i);
                    max_row = max(max_row, i);
                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }

        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }
};
