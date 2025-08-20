#include <vector>

using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int result = 0;
        int columns = matrix[0].size();
        for (int j = 0; j < columns; ++j)
        {
            result += matrix[0][j];
        }
        for (int i = 1; i < matrix.size(); ++i)
        {
            result += matrix[i][0];
            for (int j = 1; j < columns; ++j)
            {
                if (matrix[i][j] > 0)
                {
                    matrix[i][j] = min(min(matrix[i - 1][j - 1], matrix[i - 1][j]), matrix[i][j - 1]) + 1;
                }
                result += matrix[i][j];
            }
        }
        return result;
    }
};
