#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        int n = fruits.size();

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            result += fruits[i][i];
        }

        vector<int> current(n / 2, 0);
        vector<int> temp_current(n / 2, 0);
        current[0] = fruits[n - 1][0];
        // cout << current[0] << endl;
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            {
                int temp = current[j];
                if (j > 0)
                {
                    temp = max(temp, current[j - 1]);
                }
                if (j < i && j + 1 < n / 2)
                {
                    temp = max(temp, current[j + 1]);
                }
                temp_current[j] = temp;
            }
            for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            {
                current[j] = temp_current[j] + fruits[n - 1 - j][i];
                // cout << current[j] << ' ';
            }
            // cout << endl;
        }
        result += current[0];

        fill(current.begin(), current.end(), 0);
        fill(temp_current.begin(), temp_current.end(), 0);
        current[0] = fruits[0][n - 1];
        // cout << current[0] << endl;
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            {
                int temp = current[j];
                if (j > 0)
                {
                    temp = max(temp, current[j - 1]);
                }
                if (j < i && j + 1 < n / 2)
                {
                    temp = max(temp, current[j + 1]);
                }
                temp_current[j] = temp;
            }
            for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            {
                current[j] = temp_current[j] + fruits[i][n - 1 - j];
                // cout << current[j] << ' ';
            }
            // cout << endl;
        }
        result += current[0];

        return result;
    }
};
