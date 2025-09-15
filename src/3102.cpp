#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumDistance(vector<vector<int>> &points)
    {
        int n = points.size();

        int maxx1 = INT_MIN;
        int maxx2 = INT_MIN;
        int minx1 = INT_MAX;
        int minx2 = INT_MAX;
        int maxy1 = INT_MIN;
        int maxy2 = INT_MIN;
        int miny1 = INT_MAX;
        int miny2 = INT_MAX;

        bool xmaxymax = false;
        bool xmaxymin = false;
        bool xminymax = false;
        bool xminymin = false;

        for (int i = 0; i < n; ++i)
        {
            const auto &point = points[i];

            int x = point[0] + point[1];
            int y = point[0] - point[1];

            bool xmax = false;
            bool xmin = false;
            bool ymax = false;
            bool ymin = false;

            // max x
            if (x > maxx2)
            {
                if (x > maxx1)
                {
                    xmaxymax = false;
                    xmaxymin = false;

                    xmax = true;
                    maxx2 = maxx1;
                    maxx1 = x;
                }
                else if (x == maxx1)
                {
                    xmax = true;
                    maxx2 = maxx1;
                    maxx1 = x;
                }
                else
                {
                    maxx2 = x;
                }
            }

            // min x
            if (x < minx2)
            {
                if (x < minx1)
                {
                    xminymax = false;
                    xminymin = false;

                    xmin = true;
                    minx2 = minx1;
                    minx1 = x;
                }

                else if (x == minx1)
                {
                    xmin = true;
                    minx2 = minx1;
                    minx1 = x;
                }
                else
                {
                    minx2 = x;
                }
            }

            // max y
            if (y > maxy2)
            {
                if (y > maxy1)
                {
                    xmaxymax = false;
                    xminymax = false;

                    ymax = true;
                    maxy2 = maxy1;
                    maxy1 = y;
                }
                else if (y == maxy1)
                {
                    ymax = true;
                    maxy2 = maxy1;
                    maxy1 = y;
                }
                else
                {
                    maxy2 = y;
                }
            }

            // min y
            if (y < miny2)
            {
                if (y < miny1)
                {
                    xmaxymin = false;
                    xminymin = false;

                    ymin = true;
                    miny2 = miny1;
                    miny1 = y;
                }
                else if (y == miny1)
                {
                    ymin = true;
                    miny2 = miny1;
                    miny1 = y;
                }
                else
                {
                    miny2 = y;
                }
            }

            if (xmax)
            {
                if (ymax)
                {
                    xmaxymax = true;
                }
                if (ymin)
                {
                    xmaxymin = true;
                }
            }
            if (xmin)
            {
                if (ymax)
                {
                    xminymax = true;
                }
                if (ymin)
                {
                    xminymin = true;
                }
            }
        }

        int result = min(min(max(maxx1 - minx2, maxy1 - miny1),
                             max(maxx2 - minx1, maxy1 - miny1)),
                         min(max(maxx1 - minx1, maxy1 - miny2),
                             max(maxx1 - minx1, maxy2 - miny1)));
        if (xmaxymax)
        {
            result = min(result, max(maxx2 - minx1, maxy2 - miny1));
        }
        if (xmaxymin)
        {
            result = min(result, max(maxx2 - minx1, maxy1 - miny2));
        }
        if (xminymax)
        {
            result = min(result, max(maxx1 - minx2, maxy2 - miny1));
        }
        if (xminymin)
        {
            result = min(result, max(maxx1 - minx2, maxy1 - miny2));
        }
        return result;
    }
};