
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row_sum(n, 0);
        vector<int> col_sum(m, 0);
        set<int> i_set;
        set<int> j_set;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j])
                {
                    i_set.insert(i);
                    j_set.insert(j);
                    ++row_sum[i];
                    ++col_sum[j];
                }
            }
        }

        return min(minimumSum3H(grid, row_sum, col_sum, i_set, j_set), minimumSum3V(grid, row_sum, col_sum, i_set, j_set));
    }

    static int minimumSum3H(const vector<vector<int>> &grid, const vector<int> &row_sum, const vector<int> &col_sum, const set<int> &i_set, const set<int> &j_set)
    {
        int result = (*i_set.rbegin() - *i_set.begin() + 1) * (*j_set.rbegin() - *j_set.begin() + 1);

        vector<int> col_sum_1(col_sum.size(), 0);
        vector<int> col_sum_2(col_sum);

        set<int> i_set_1;
        set<int> i_set_2 = i_set;

        set<int> j_set_1;
        set<int> j_set_2 = j_set;

        while (i_set_2.size() >= 2)
        {
            int i = *i_set_2.begin();
            i_set_2.erase(i_set_2.begin());
            i_set_1.insert(i);

            for (int j : j_set)
            {
                if (grid[i][j])
                {
                    ++col_sum_1[j];
                    --col_sum_2[j];

                    j_set_1.insert(j);
                    if (!col_sum_2[j])
                    {
                        j_set_2.erase(j);
                    }
                }
            }

            int area1 = (*i_set_1.rbegin() - *i_set_1.begin() + 1) * (*j_set_1.rbegin() - *j_set_1.begin() + 1);
            int area2 = (*i_set_2.rbegin() - *i_set_2.begin() + 1) * (*j_set_2.rbegin() - *j_set_2.begin() + 1);

            int area1_2 = min(minimumSum2V(grid, row_sum, i_set_1, j_set_1), minimumSum2H(grid, col_sum_1, i_set_1, j_set_1));
            int area2_2 = min(minimumSum2V(grid, row_sum, i_set_2, j_set_2), minimumSum2H(grid, col_sum_2, i_set_2, j_set_2));

            result = min(result, min(area1 + area2_2, area1_2 + area2));
        }

        return result;
    }

    static int minimumSum3V(const vector<vector<int>> &grid, const vector<int> &row_sum, const vector<int> &col_sum, const set<int> &i_set, const set<int> &j_set)
    {
        int result = (*i_set.rbegin() - *i_set.begin() + 1) * (*j_set.rbegin() - *j_set.begin() + 1);

        vector<int> row_sum_1(row_sum.size(), 0);
        vector<int> row_sum_2(row_sum);

        set<int> i_set_1;
        set<int> i_set_2 = i_set;

        set<int> j_set_1;
        set<int> j_set_2 = j_set;

        while (j_set_2.size() >= 2)
        {
            int j = *j_set_2.begin();
            j_set_2.erase(j_set_2.begin());
            j_set_1.insert(j);

            for (int i : i_set)
            {
                if (grid[i][j])
                {
                    ++row_sum_1[i];
                    --row_sum_2[i];

                    i_set_1.insert(i);
                    if (!row_sum_2[i])
                    {
                        i_set_2.erase(i);
                    }
                }
            }

            int area1 = (*i_set_1.rbegin() - *i_set_1.begin() + 1) * (*j_set_1.rbegin() - *j_set_1.begin() + 1);
            int area2 = (*i_set_2.rbegin() - *i_set_2.begin() + 1) * (*j_set_2.rbegin() - *j_set_2.begin() + 1);

            int area1_2 = min(minimumSum2V(grid, row_sum_1, i_set_1, j_set_1), minimumSum2H(grid, col_sum, i_set_1, j_set_1));
            int area2_2 = min(minimumSum2V(grid, row_sum_2, i_set_2, j_set_2), minimumSum2H(grid, col_sum, i_set_2, j_set_2));

            result = min(result, min(area1 + area2_2, area1_2 + area2));
        }

        return result;
    }

    static int minimumSum2H(const vector<vector<int>> &grid, const vector<int> &col_sum, const set<int> &i_set, const set<int> &j_set)
    {
        int result = (*i_set.rbegin() - *i_set.begin() + 1) * (*j_set.rbegin() - *j_set.begin() + 1);

        // vector<int> col_sum_1(col_sum.size(), 0);
        vector<int> col_sum_2(col_sum);

        set<int> i_set_1;
        set<int> i_set_2 = i_set;

        set<int> j_set_1;
        set<int> j_set_2 = j_set;

        while (i_set_2.size() >= 2)
        {
            int i = *i_set_2.begin();
            i_set_2.erase(i_set_2.begin());
            i_set_1.insert(i);

            for (int j : j_set)
            {
                if (grid[i][j])
                {
                    // ++col_sum_1[j];
                    --col_sum_2[j];

                    j_set_1.insert(j);
                    if (!col_sum_2[j])
                    {
                        j_set_2.erase(j);
                    }
                }
            }

            int area1 = (*i_set_1.rbegin() - *i_set_1.begin() + 1) * (*j_set_1.rbegin() - *j_set_1.begin() + 1);
            int area2 = (*i_set_2.rbegin() - *i_set_2.begin() + 1) * (*j_set_2.rbegin() - *j_set_2.begin() + 1);

            result = min(result, area1 + area2);
        }

        return result;
    }

    static int minimumSum2V(const vector<vector<int>> &grid, const vector<int> &row_sum, const set<int> &i_set, const set<int> &j_set)
    {
        int result = (*i_set.rbegin() - *i_set.begin() + 1) * (*j_set.rbegin() - *j_set.begin() + 1);

        // vector<int> row_sum_1(row_sum.size(), 0);
        vector<int> row_sum_2(row_sum);

        set<int> i_set_1;
        set<int> i_set_2 = i_set;

        set<int> j_set_1;
        set<int> j_set_2 = j_set;

        while (j_set_2.size() >= 2)
        {
            int j = *j_set_2.begin();
            j_set_2.erase(j_set_2.begin());
            j_set_1.insert(j);

            for (int i : i_set)
            {
                if (grid[i][j])
                {
                    // ++row_sum_1[i];
                    --row_sum_2[i];

                    i_set_1.insert(i);
                    if (!row_sum_2[i])
                    {
                        i_set_2.erase(i);
                    }
                }
            }

            int area1 = (*i_set_1.rbegin() - *i_set_1.begin() + 1) * (*j_set_1.rbegin() - *j_set_1.begin() + 1);
            int area2 = (*i_set_2.rbegin() - *i_set_2.begin() + 1) * (*j_set_2.rbegin() - *j_set_2.begin() + 1);

            result = min(result, area1 + area2);
        }

        return result;
    }
};
