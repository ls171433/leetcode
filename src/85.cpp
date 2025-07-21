#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int result = 0;

        std::stack<int, vector<int>> rect_begins;
        for (int j = 0; j < m; ++j)
        {
            if (matrix[0][j] == '1')
            {
                matrix[0][j] = 1;
            }
            else
            {
                matrix[0][j] = 0;
            }

            int num = matrix[0][j];
            while (rect_begins.size() < num)
            {
                rect_begins.push(j);
            }
            while (rect_begins.size() > num)
            {
                int k = rect_begins.top();
                result = max<int>(result, (j - k) * rect_begins.size());
                rect_begins.pop();
            }
        }
        while (!rect_begins.empty())
        {
            int k = rect_begins.top();
            result = max<int>(result, (m - k) * rect_begins.size());
            rect_begins.pop();
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }

                int num = static_cast<unsigned char>(matrix[i][j]);
                while (rect_begins.size() < num)
                {
                    rect_begins.push(j);
                }
                while (rect_begins.size() > num)
                {
                    int k = rect_begins.top();
                    result = max<int>(result, (j - k) * rect_begins.size());
                    rect_begins.pop();
                }
            }
            while (!rect_begins.empty())
            {
                int k = rect_begins.top();
                result = max<int>(result, (m - k) * rect_begins.size());
                rect_begins.pop();
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << Solution().maximalRectangle(matrix) << endl;
    vector<char> temp;
    for (int i = 0; i < 200; ++i)
    {
        temp.push_back('1');
    }
    matrix.clear();
    for (int i = 0; i < 200; ++i)
    {
        matrix.push_back(temp);
    }
    cout << Solution().maximalRectangle(matrix) << endl;
}
