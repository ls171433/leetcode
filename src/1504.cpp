#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 1; i < mat.size(); ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (mat[i][j])
                {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }

        int result = 0;
        vector<int> stack;
        vector<int> sum(m, 0);
        for (int i = 0; i < n; ++i)
        {
            stack.clear();
            stack.reserve(m);
            for (int j = 0; j < m; ++j)
            {
                while (!stack.empty() && mat[i][stack.back()] >= mat[i][j])
                {
                    stack.pop_back();
                }
                if (stack.empty())
                {
                    sum[j] = mat[i][j] * (j + 1);
                }
                else
                {
                    sum[j] = sum[stack.back()] + mat[i][j] * (j - stack.back());
                }
                // cout << sum[j] << ' ';
                result += sum[j];
                stack.push_back(j);
            }
            // cout << endl;
        }
        return result;
    }
};
