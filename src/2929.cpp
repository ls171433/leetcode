#include <algorithm>

using namespace std;

class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        if (limit * 3 < n)
        {
            return 0;
        }
        else if (limit * 2 < n)
        {
            return static_cast<long long>(n + 2) * (n + 1) / 2 - 3 * static_cast<long long>(n - limit + 1) * (n - limit) / 2 + 3 * static_cast<long long>(n - 2 * limit) * (n - 2 * limit - 1) / 2;
        }
        else if (limit < n)
        {
            return static_cast<long long>(n + 2) * (n + 1) / 2 - 3 * static_cast<long long>(n - limit + 1) * (n - limit) / 2;
        }
        else
        {
            return static_cast<long long>(n + 2) * (n + 1) / 2;
        }
    }
};
