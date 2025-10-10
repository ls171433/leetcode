#include <array>
#include <vector>

using namespace std;

class Solution
{
public:
    int m, n;
    inline static constexpr array<array<int, 2>, 4> directions = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<signed char>> pacific(m, vector<signed char>(n, false));
        vector<vector<signed char>> atlantic(m, vector<signed char>(n, false));

        for (int j = 0; j < n; j++)
        {
            dfs(0, j, heights, pacific);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, heights, pacific);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(m - 1, j, heights, atlantic);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(int x, int y, const vector<vector<int>> &heights, vector<vector<signed char>> &visited)
    {
        visited[x][y] = true;

        for (auto &direction : directions)
        {
            int xx = x + direction[0];
            int yy = y + direction[1];

            if (xx < 0 || xx >= m || yy < 0 || yy >= n)
            {
                continue;
            }
            if (visited[xx][yy])
            {
                continue;
            }
            if (heights[xx][yy] < heights[x][y])
            {
                continue;
            }

            dfs(xx, yy, heights, visited);
        }
    }
};
