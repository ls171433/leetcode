#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double max_area = 0.0;
        int n = points.size();

        for (int i = 0; i < n; ++i)
        {
            auto points_i0 = points[i][0];
            auto points_i1 = points[i][1];
            for (int j = i + 1; j < n; ++j)
            {
                auto points_j0 = points[j][0];
                auto points_j1 = points[j][1];
                for (int k = j + 1; k < n; ++k)
                {
                    auto points_k0 = points[k][0];
                    auto points_k1 = points[k][1];
                    double area = 0.5 * std::abs(points_i0 * (points_j1 - points_k1) +
                                                 points_j0 * (points_k1 - points_i1) +
                                                 points_k0 * (points_i1 - points_j1));
                    max_area = std::max(max_area, area);
                }
            }
        }

        return max_area;
    }
};
