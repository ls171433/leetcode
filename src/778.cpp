#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        using element_type = tuple<int, int, int>;
        priority_queue<element_type, vector<element_type>, greater<>> pq;

        int min_height = -1;
        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = -1;

        while (!pq.empty())
        {
            auto [height, x, y] = pq.top();
            pq.pop();

            min_height = max(min_height, height);

            if (x == n - 1 && y == n - 1)
            {
                return min_height;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] >= 0)
                {
                    pq.emplace(grid[nx][ny], nx, ny);
                    grid[nx][ny] = -1;
                }
            }
        }

        return -1;
    }
};
