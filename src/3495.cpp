#include <vector>

using namespace std;

class Solution
{
public:
    long long minOperations(vector<vector<int>> &queries)
    {
        long long result = 0;
        for (auto &query : queries)
        {
            result += min_operations(query[0], query[1]);
        }
        return result;
    }

    static long long min_operations(int start, int end)
    {
        long long count = 0;
        long long basic_number = 1;
        while (basic_number <= end)
        {
            if (basic_number < start)
            {
                count += end - start + 1;
            }
            else
            {
                count += end - basic_number + 1;
            }
            basic_number <<= 2;
        }

        return (count + 1) / 2;
    }
};
