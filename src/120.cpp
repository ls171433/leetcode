#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> part_result;
        part_result.reserve(n);
        part_result.push_back(triangle[0][0]);
        for (int i = 1; i < n; ++i)
        {
            part_result.push_back(part_result[i - 1] + triangle[i][i]);
            for (int j = i - 1; j >= 1; --j)
            {
                part_result[j] = min(part_result[j - 1], part_result[j]) + triangle[i][j];
            }
            part_result[0] += triangle[i][0];
        }
        int result = part_result[0];
        for (int i = 1; i < n; ++i)
        {
            result = min(result, part_result[i]);
        }
        return result;
    }
};
