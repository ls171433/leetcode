#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> temp;
        temp.reserve(n);

        for (int j = n - 1; j > 0; --j)
        {
            temp.push_back(0);
            for (int i = 0; i + j < n; ++i)
            {
                temp[i] = grid[i][i + j];
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i + j < n; ++i)
            {
                grid[i][i + j] = temp[i];
            }
        }

        temp.push_back(0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j + i < n; ++j)
            {
                temp[j] = grid[i + j][j];
            }
            sort(temp.begin(), temp.end(), greater<int>());
            for (int j = 0; j + i < n; ++j)
            {
                grid[i + j][j] = temp[j];
            }
            temp.pop_back();
        }

        return grid;
    }
};
