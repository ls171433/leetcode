#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            vector<signed char> number_count(9, 0);
            for (int j = 0; j < 9; ++j)
            {
                auto &c = board[i][j];
                if (c != '.')
                {
                    int number = c - '1';
                    if (number_count[number] == 1)
                    {
                        return false;
                    }
                    number_count[number] = 1;
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            vector<signed char> number_count(9, 0);
            for (int j = 0; j < 9; ++j)
            {
                auto &c = board[j][i];
                if (c != '.')
                {
                    int number = c - '1';
                    if (number_count[number] == 1)
                    {
                        return false;
                    }
                    number_count[number] = 1;
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            vector<signed char> number_count(9, 0);
            for (int j = 0; j < 9; ++j)
            {
                auto &c = board[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + (j % 3)];
                if (c != '.')
                {
                    int number = c - '1';
                    if (number_count[number] == 1)
                    {
                        return false;
                    }
                    number_count[number] = 1;
                }
            }
        }

        return true;
    }
};
