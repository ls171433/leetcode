#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> *p_grid = nullptr;
    int n = 0;
    int m = 0;

    vector<short> memo;
    short max_result = 0;

    int hash_xyxxyy(int x, int y, int xx, int yy)
    {
        return (x * m + y) << 2 | ((xx > 0 ? 1 : 0) << 1) | (yy > 0 ? 1 : 0);
    }

    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        p_grid = &grid;
        n = grid.size();
        m = grid[0].size();
        memo.clear();
        memo.resize(n * m * 4, -1);
        max_result = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    if (n - i > max_result)
                    {
                        max_result = max(max_result, dfs(i, j, 1, 1, false));
                    }
                    if (i + 1 > max_result)
                    {
                        max_result = max(max_result, dfs(i, j, -1, -1, false));
                    }
                    if (m - j > max_result)
                    {
                        max_result = max(max_result, dfs(i, j, -1, 1, false));
                    }
                    if (j + 1 > max_result)
                    {
                        max_result = max(max_result, dfs(i, j, 1, -1, false));
                    }
                }
            }
        }

        return max_result;
    }

    short dfs(int x, int y, int xx, int yy, bool turn)
    {
        const auto &grid = *p_grid;

        short result = 1;

        int current_hash = hash_xyxxyy(x, y, xx, yy);
        if (turn && memo[current_hash] != -1)
        {
            return memo[current_hash];
        }

        if (!turn && grid[x][y] != 1)
        {
            result = max(result, dfs(x, y, yy, -xx, true));
        }

        if (x + xx >= 0 && x + xx < n && y + yy >= 0 && y + yy < m)
        {
            int expected = 2;
            if (grid[x][y] == 2)
            {
                expected = 0;
            }

            if (grid[x + xx][y + yy] == expected)
            {
                result = max<short>(result, 1 + dfs(x + xx, y + yy, xx, yy, turn));
            }
        }

        if (turn)
        {
            memo[current_hash] = result;
        }

        return result;
    }
};
