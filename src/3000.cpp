#include <vector>

using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int max_diagonal_2 = 0;
        int max_area = 0;
        for (const auto &dim : dimensions)
        {
            int diagonal_2 = dim[0] * dim[0] + dim[1] * dim[1];
            if (diagonal_2 > max_diagonal_2)
            {
                max_diagonal_2 = diagonal_2;
                max_area = dim[0] * dim[1];
            }
            else if (diagonal_2 == max_diagonal_2)
            {
                int area = dim[0] * dim[1];
                if (area > max_area)
                {
                    max_area = area;
                }
            }
        }
        return max_area;
    }
};
