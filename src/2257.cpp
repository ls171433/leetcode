#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr unsigned char GUARD = 1 << 7;
    static constexpr unsigned char WALL = 1 << 6;
    static constexpr unsigned char UP = 1 << 3;
    static constexpr unsigned char DOWN = 1 << 2;
    static constexpr unsigned char LEFT = 1 << 1;
    static constexpr unsigned char RIGHT = 1 << 0;
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<unsigned char>> grid(m, vector<unsigned char>(n, 0));

        for (const auto &wall : walls)
        {
            grid[wall[0]][wall[1]] |= WALL;
        }

        for (const auto &guard : guards)
        {
            grid[guard[0]][guard[1]] |= GUARD;
        }

        for (const auto &guard : guards)
        {
            int x = guard[0];
            int y = guard[1];
            int xx = x;
            while (--xx >= 0)
            {
                if ((grid[xx][y] & WALL) || (grid[xx][y] & GUARD) || (grid[xx][y] & RIGHT))
                {
                    break;
                }
                grid[xx][y] |= LEFT;
            }
            xx = x;
            while (++xx < m)
            {
                if ((grid[xx][y] & WALL) || (grid[xx][y] & GUARD) || (grid[xx][y] & LEFT))
                {
                    break;
                }
                grid[xx][y] |= RIGHT;
            }
            int yy = y;
            while (--yy >= 0)
            {
                if ((grid[x][yy] & WALL) || (grid[x][yy] & GUARD) || (grid[x][yy] & DOWN))
                {
                    break;
                }
                grid[x][yy] |= UP;
            }
            yy = y;
            while (++yy < n)
            {
                if ((grid[x][yy] & WALL) || (grid[x][yy] & GUARD) || (grid[x][yy] & UP))
                {
                    break;
                }
                grid[x][yy] |= DOWN;
            }
        }

        int result = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ++result;
                }
            }
        }
        return result;
    }
};
