#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> prefix_products;
        prefix_products.reserve(32);
        prefix_products.push_back(1);
        vector<int> prefix_product_reverses;
        prefix_product_reverses.reserve(32);
        prefix_product_reverses.push_back(1);
        for (int i = 0; i <= 30 && (1 << i) <= n; ++i)
        {
            if (n & (1 << i))
            {
                long long current = static_cast<long long>(prefix_products.back()) * static_cast<long long>(1 << i) % MOD;
                prefix_products.push_back(static_cast<int>(current));
                prefix_product_reverses.push_back(reverse(static_cast<int>(current)));
            }
        }

        vector<int> result;
        result.reserve(queries.size());
        for (const auto &query : queries)
        {
            long long product = static_cast<long long>(prefix_products[query[1] + 1]) * static_cast<long long>(prefix_product_reverses[query[0]]) % MOD;
            result.push_back(static_cast<int>(product));
        }
        return result;
    }

    static int reverse(int n)
    {
        long long nn = n;
        long long result = 1;
        int exp = MOD - 2;
        while (exp)
        {
            if (exp & 1)
            {
                result = (result * nn) % MOD;
            }
            nn = (nn * nn) % MOD;
            exp >>= 1;
        }
        return static_cast<int>(result);
    }
};
