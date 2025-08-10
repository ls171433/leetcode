#include <iostream>

using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        if (n >= 1e9)
        {
            return false;
        }

        int digits_n[10] = {0};
        int min = 1;

        int temp = n;
        while (temp > 0)
        {
            ++digits_n[temp % 10];
            temp /= 10;
            min *= 10;
        }
        min /= 10;

        int m = 1;
        int digits_m[10] = {0};
        while (m < min)
        {
            m <<= 1;
        }

        while (m <= min * 10)
        {
            for (int i = 0; i < 10; ++i)
            {
                digits_m[i] = 0;
            }
            temp = m;
            while (temp > 0)
            {
                ++digits_m[temp % 10];
                temp /= 10;
            }
            bool isSame = true;
            for (int i = 0; i < 10; ++i)
            {
                // cout << "digits_n[" << i << "] = " << digits_n[i] << ", digits_m[" << i << "] = " << digits_m[i] << endl;
                if (digits_n[i] != digits_m[i])
                {
                    isSame = false;
                    break;
                }
            }

            if (isSame)
            {
                return true;
            }

            m <<= 1;
        }

        return false;
    }
};
