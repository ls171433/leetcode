
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> result;
        result.reserve(n * m);
        for (int sum = 0; sum <= (n - 1) + (m - 1); ++sum)
        {
            int min_i = max(0, sum - (m - 1));
            int max_i = min(n - 1, sum);
            if (sum % 2)
            {
                for (int i = min_i; i <= max_i; ++i)
                {
                    result.push_back(mat[i][sum - i]);
                }
            }
            else
            {
                for (int i = max_i; i >= min_i; --i)
                {
                    result.push_back(mat[i][sum - i]);
                }
            }
        }

        return result;
    }
};
