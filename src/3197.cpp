
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> grid_sum;

    int minimumSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        grid_sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                grid_sum[i + 1][j + 1] = grid[i][j] + grid_sum[i][j + 1] + grid_sum[i + 1][j] - grid_sum[i][j];
            }
        }

        int result = INT_MAX;
        for (int i1 = 1; i1 < n; ++i1)
        {
            for (int j2 = 1; j2 < m; ++j2)
            {
                result = min(result, min_area(0, 0, i1, m) + min_area(i1, 0, n, j2) + min_area(i1, j2, n, m));
                result = min(result, min_area(0, 0, i1, j2) + min_area(0, j2, i1, m) + min_area(i1, 0, n, m));
            }
            for (int i2 = i1 + 1; i2 < n; ++i2)
            {
                result = min(result, min_area(0, 0, i1, m) + min_area(i1, 0, i2, m) + min_area(i2, 0, n, m));
            }
        }
        for (int j1 = 1; j1 < m; ++j1)
        {
            for (int i2 = 1; i2 < n; ++i2)
            {
                result = min(result, min_area(0, 0, n, j1) + min_area(0, j1, i2, m) + min_area(i2, j1, n, m));
                result = min(result, min_area(0, 0, i2, j1) + min_area(i2, 0, n, j1) + min_area(0, j1, n, m));
            }
            for (int j2 = j1 + 1; j2 < m; ++j2)
            {
                result = min(result, min_area(0, 0, n, j1) + min_area(0, j1, n, j2) + min_area(0, j2, n, m));
            }
        }

        return result;
    }

    int get_sum(int x1, int y1, int x2, int y2)
    {
        return grid_sum[x2][y2] - grid_sum[x1][y2] - grid_sum[x2][y1] + grid_sum[x1][y1];
    }

    int min_area(int x1, int y1, int x2, int y2)
    {
        return min_area_1(x1, y1, x2, y2);
        // return min_area_2(x1, y1, x2, y2);
    }

    int min_area_1(int x1, int y1, int x2, int y2)
    {
        int sum = get_sum(x1, y1, x2, y2);
        if (sum <= 1)
        {
            return sum;
        }

        while (x2 - x1 > 1 && get_sum(x1, y1, x1 + 1, y2) == 0)
        {
            ++x1;
        }
        while (x2 - x1 > 1 && get_sum(x2 - 1, y1, x2, y2) == 0)
        {
            --x2;
        }
        while (y2 - y1 > 1 && get_sum(x1, y1, x2, y1 + 1) == 0)
        {
            ++y1;
        }
        while (y2 - y1 > 1 && get_sum(x1, y2 - 1, x2, y2) == 0)
        {
            --y2;
        }

        return (x2 - x1) * (y2 - y1);
    }

    int min_area_2(int x1, int y1, int x2, int y2)
    {
        int sum = get_sum(x1, y1, x2, y2);
        if (sum <= 1)
        {
            return sum;
        }

        int l, r;

        l = x1, r = x2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (get_sum(l, y1, mid + 1, y2) == 0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        x1 = l;

        l = x1, r = x2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (get_sum(mid, y1, x2, y2) == 0)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        x2 = r;

        l = y1, r = y2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (get_sum(x1, l, x2, mid + 1) == 0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        y1 = l;

        l = y1, r = y2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (get_sum(x1, mid, x2, y2) == 0)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        y2 = r;

        return (x2 - x1) * (y2 - y1);
    }
};
