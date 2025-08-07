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
        current[0] = fruits[n - 1][0];
        // cout << current[0] << endl;
        for (int i = 1; i < n - 1; ++i)
        {
            int last = 0;
            for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            {
                int temp = max(current[j], last);
                if (j < i && j + 1 < n / 2)
                {
                    temp = max(temp, current[j + 1]);
                }
                last = current[j];
                current[j] = temp + fruits[n - 1 - j][i];
            }
            // for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            // {
            //     cout << current[j] << ' ';
            // }
            // cout << endl;
        }
        result += current[0];

        fill(current.begin(), current.end(), 0);
        current[0] = fruits[0][n - 1];
        // cout << current[0] << endl;
        for (int i = 1; i < n - 1; ++i)
        {
            int last = 0;
            for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            {
                int temp = max(current[j], last);
                if (j < i && j + 1 < n / 2)
                {
                    temp = max(temp, current[j + 1]);
                }
                last = current[j];
                current[j] = temp + fruits[i][n - 1 - j];
            }
            // for (int j = 0; j <= i && j <= n - 2 - i; ++j)
            // {
            //     cout << current[j] << ' ';
            // }
            // cout << endl;
        }
        result += current[0];

        return result;
    }
};
