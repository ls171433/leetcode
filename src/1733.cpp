#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int m = languages.size();

        for (auto &language : languages)
        {
            sort(language.begin(), language.end());
        }

        vector<signed char> to_teach_user(m, 0);
        for (auto &friendship : friendships)
        {
            int user_1 = friendship[0] - 1;
            int user_2 = friendship[1] - 1;

            if ((!to_teach_user[user_1] || !to_teach_user[user_2]) && !has_common_language(languages[user_1], languages[user_2]))
            {
                to_teach_user[user_1] = 1;
                to_teach_user[user_2] = 1;
            }
        }

        vector<int> to_teach_user_count(n, 0);
        int to_teach_size;
        for (int i = 0; i < m; ++i)
        {
            if (to_teach_user[i] == 0)
            {
                continue;
            }

            ++to_teach_size;
            for (int language : languages[i])
            {
                ++to_teach_user_count[language - 1];
            }
        }

        int result = to_teach_size;
        for (int count : to_teach_user_count)
        {
            result = min(result, to_teach_size - count);
        }
        return result;
    }

    bool has_common_language(const vector<int> &a, const vector<int> &b)
    {
        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                return true;
            }
            else if (a[i] < b[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }

        return false;
    }
};
