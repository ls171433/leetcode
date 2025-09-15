#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        size_t columns = grid[0].size();
        size_t rows = grid.size();

        vector<int> counts;
        counts.resize(10);

        vector<int> total_counts;
        total_counts.resize(10);

        vector<vector<int>> total_counts_temp;
        total_counts_temp.resize(10);
        for (int n = 0; n < 10; ++n)
        {
            counts[n] = 0;
            total_counts[n] = 0;
            total_counts_temp[n].resize(10);
        }

        for (size_t i = 0; i < columns; ++i)
        {
            for (int n = 0; n < 10; ++n)
            {
                counts[n] = rows;
            }
            for (size_t j = 0; j < rows; ++j)
            {
                --counts[grid[j][i]];
            }

            for (int n = 0; n < 10; ++n)
            {
                for (int m = 0; m < 10; ++m)
                {
                    total_counts_temp[m][n] = total_counts[n] + counts[m];
                }
                total_counts_temp[n][n] = INT_MAX;
            }

            for (int n = 0; n < 10; ++n)
            {
                total_counts[n] = *min_element(total_counts_temp[n].begin(), total_counts_temp[n].end());
            }
        }
        return *min_element(total_counts.begin(), total_counts.end());
    }
};
