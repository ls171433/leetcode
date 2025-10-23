#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        int left = 0;
        int right = 0;
        int size = s.size();
        for (int i = 0; i < size - 2 - i; ++i)
        {
            int mod = c_mod_10(size - 2, i);
            int j = size - 2 - i;
            // cout << mod << ' ' << s[i] << ' ' << s[j] << endl;
            left += (s[i] - '0' + s[j] - '0') * mod;
            right += (s[i + 1] - '0' + s[j + 1] - '0') * mod;
        }
        if (size % 2 == 0)
        {
            int i = size / 2 - 1;
            int mod = c_mod_10(size - 2, i);
            // cout << mod << ' ' << s[i] << endl;
            left += (s[i] - '0') * mod;
            right += (s[i + 1] - '0') * mod;
        }
        // cout << left << endl << right << endl;
        return left % 10 == right % 10;
    }

    static int c(int n, int k)
    {
        static constexpr array<array<int, 5>, 5> temp = {{{{1, 0, 0, 0, 0}}, {{1, 1, 0, 0, 0}}, {{1, 2, 1, 0, 0}}, {{1, 3, 3, 1, 0}}, {{1, 4, 6, 4, 1}}}};
        return temp[n][k];
    }

    static int c_mod(int n, int k, int p)
    {
        if (k < 0 || k > n)
        {
            return 0;
        }
        if (k == 0 || k == n)
        {
            return 1;
        }
        int cc = c(n % p, k % p);
        if (cc == 0)
        {
            return 0;
        }
        return c_mod(n / p, k / p, p) * cc % p;
    }

    static int c_mod_10(int n, int k)
    {
        return (c_mod(n, k, 5) * 6 + c_mod(n, k, 2) * 5) % 10;
    }
};
