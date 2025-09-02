#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();
        int result = 0;

        sort(points.begin(), points.end(), compare);

        vector<int> points_indexs;

        int last_x = INT_MIN;
        int last_y = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            const auto &point = points[i];
            int x = point[0];
            int y = point[1];

            int y_max = INT_MAX;
            if (x != last_x)
            {
                points_indexs.push_back(i);
                last_x = x;
            }
            else
            {
                y_max = last_y;
                ++result;
                // cout << x << ' ' << y << ' ' << y_max << endl;
            }
            last_y = y;

            for (int k = points_indexs.size() - 1; k - 1 >= 0; --k)
            {
                int j_begin = points_indexs[k - 1];
                int j_end = points_indexs[k];
                for (int j = j_end - 1; j >= j_begin; --j)
                {
                    const auto &point2 = points[j];
                    int y2 = point2[1];
                    if (y2 < y)
                    {
                        continue;
                    }
                    else if (y2 < y_max)
                    {
                        y_max = y2;
                        ++result;
                        // cout << x << ' ' << y << ' ' << y2 << endl;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return result;
    }

    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] != b[0])
        {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
};
