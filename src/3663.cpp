class Solution
{
public:
    int getLeastFrequentDigit(int n)
    {
        int times[10] = {0};
        while (n > 0)
        {
            ++times[n % 10];
            n /= 10;
        }

        int min = 100;
        int result = -1;
        for (int i = 0; i < 10; ++i)
        {
            if (times[i] > 0 && times[i] < min)
            {
                min = times[i];
                result = i;
            }
        }
        return result;
    }
};
