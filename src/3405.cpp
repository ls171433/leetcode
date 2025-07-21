#include <iostream>

using namespace std;

class Solution
{
public:
    static constexpr unsigned long long mod = 1000000007ull;

    unsigned long long pow_mod(unsigned long long base, unsigned long long exp)
    {
        unsigned long long result = 1;
        while (exp)
        {
            if (exp & 1)
            {
                result *= base;
                result %= mod;
            }
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        return result;
    }

    unsigned long long fact_mod(unsigned long long base)
    {
        unsigned long long result = 1;
        for (unsigned long long n = 2; n <= base; ++n)
        {
            result *= n;
            result %= mod;
        }
        return result;
    }

    unsigned long long inv_fact_mod(unsigned long long base)
    {
        return pow_mod(fact_mod(base), mod - 2);
    }

    int countGoodArrays(int n, int m, int k)
    {
        unsigned long long result = m;

        result *= pow_mod(static_cast<unsigned long long>(m - 1), static_cast<unsigned long long>(n - k - 1));
        result %= mod;

        unsigned long long result_2 = 1;
        result_2 *= fact_mod(static_cast<unsigned long long>(n - 1));
        result_2 %= mod;
        result_2 *= inv_fact_mod(static_cast<unsigned long long>(k));
        result_2 %= mod;
        result_2 *= inv_fact_mod(static_cast<unsigned long long>(n - k - 1));
        result_2 %= mod;

        return result * result_2 % mod;
    }
};

int main()
{
    for (unsigned long long i = 0; i < 10; ++i)
    {
        cout << Solution().inv_fact_mod(i) << endl;
    }
}