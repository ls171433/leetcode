#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;
        int negative_count = 0;
        int zero_count = 0;
        int min_num_abs = INT_MAX;
        for (const auto &row : matrix)
        {
            for (const auto &num : row)
            {
                if (num > 0)
                {
                    sum += num;
                    min_num_abs = min(min_num_abs, num);
                }
                else if (num < 0)
                {
                    sum += -num;
                    ++negative_count;
                    min_num_abs = min(min_num_abs, -num);
                }
                else
                {
                    ++zero_count;
                }
            }
        }

        if (zero_count > 0 || negative_count % 2 == 0)
        {
            return sum;
        }
        else
        {
            return sum - 2 * min_num_abs;
        }
    }
};
