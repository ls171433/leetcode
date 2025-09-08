class Solution
{
public:
    int countBinaryPalindromes(long long n)
    {
        int digits = 0;
        long long temp = n;
        while (temp)
        {
            ++digits;
            temp >>= 1;
        }

        if (digits == 0)
        {
            return 1;
        }

        int result = (1 << (digits / 2)) + (1 << ((digits - 1) / 2)) - 1;
        long long base = 1ll << (digits - 1) | 1ll;
        if (n < base)
        {
            return result;
        }
        ++result;

        for (int i = 0; i < (digits - 1) / 2; ++i)
        {
            long long base_temp = 1ll << (digits - 2 - i) | 1ll << (1 + i);
            if (base + base_temp <= n)
            {
                base += base_temp;
                result += 1 << ((digits - 3) / 2 - i);
            }
        }
        return result;
    }
};
