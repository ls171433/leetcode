#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end(), [](const vector<int> &left, const vector<int> &right)
             { return (left[1] < right[1]); });

        int n = events.size();

        vector<vector<int>> value(k, vector<int>(n + 1, 0));

        for (int i = 0; i < n; ++i)
        {
            int left = -1;
            int right = i;
            while (right - left > 1)
            {
                int mid = (left + right) / 2;
                if (events[mid][1] >= events[i][0])
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            int last_index = left;
            value[0][i + 1] = max(events[i][2], value[0][i]);
            // cout << value[0][i + 1] << ' ';
            for (int kk = 1; kk < k; ++kk)
            {
                value[kk][i + 1] = max(value[kk - 1][last_index + 1] + events[i][2], value[kk][i]);
                // cout << value[kk][i + 1] << ' ';
            }
            // cout << endl;
        }

        int result = value[k - 1][n];

        return result;
    }
};
