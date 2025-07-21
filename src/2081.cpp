#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long kMirror(int k, int n)
    {
        int count = 0;
        long long sum = 0;

        long long number = 0;
        vector<int> number_k_digits;
        vector<int> number_10_digits;

        for (int number = 1; number < k && count < n; ++number)
        {
            // cout << number << endl;
            ++count;
            sum += number;
        }

        for (int digits = 2; count < n; ++digits)
        {
            number_k_digits.resize(digits);
            number_k_digits[0] = 1;
            for (int i = 1; i < (digits + 1) / 2; ++i)
            {
                number_k_digits[i] = 0;
            }

            number_10_digits.resize(digits, 0);

            while (count < n)
            {
                for (int i = (digits + 1) / 2; i < digits; ++i)
                {
                    number_k_digits[i] = number_k_digits[digits - 1 - i];
                }

                /*
                for (int i = 0; i < digits; ++i)
                {
                    cout << number_k_digits[i];
                }
                cout << endl;
                //*/

                number = 0;
                long long base_k = 1;
                for (int i = 0; i < digits; ++i)
                {
                    number += number_k_digits[i] * base_k;
                    base_k *= k;
                }
                // cout << number << endl;

                int digits_10 = 0;
                long long number_temp = number;
                while (number_temp)
                {
                    number_10_digits[digits_10] = number_temp % 10;
                    number_temp /= 10;
                    ++digits_10;
                }

                /*
                for (int i = 0; i < digits_10; ++i)
                {
                    cout << number_10_digits[i];
                }
                cout << endl;
                //*/

                bool is_10_mirror = true;
                for (int i = 0; i < digits_10 / 2; ++i)
                {
                    if (number_10_digits[i] != number_10_digits[digits_10 - 1 - i])
                    {
                        is_10_mirror = false;
                    }
                }
                if (is_10_mirror)
                {
                    // cout << number << endl;
                    ++count;
                    sum += number;
                }

                ++number_k_digits[(digits - 1) / 2];
                for (int i = (digits - 1) / 2; i >= 0; --i)
                {
                    if (number_k_digits[i] >= k)
                    {
                        number_k_digits[i] = 0;
                        if (i - 1 >= 0)
                        {
                            ++number_k_digits[i - 1];
                        }
                    }
                }

                bool all_zero = true;
                for (int i = 0; i < (digits + 1) / 2; ++i)
                {
                    if (number_k_digits[i] != 0)
                    {
                        all_zero = false;
                    }
                }
                if (all_zero)
                {
                    break;
                }

                if (number_k_digits[0] == 0)
                {
                    number_k_digits[0] = 1;
                }
            }
        }

        return sum;
    }
};

int main()
{
    cout << Solution().kMirror(5, 22) << endl;
}
