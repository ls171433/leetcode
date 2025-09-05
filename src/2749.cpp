class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        long long temp = num1;
        for (int i = 0; i <= 36; ++i)
        {
            if (temp < 0)
            {
                return -1;
            }

            int count = 0;
            long long temp2 = temp;
            while (temp2)
            {
                count += (temp2 & 1);
                temp2 >>= 1;
            }
            if (count <= i && i <= temp)
            {
                return i;
            }

            temp -= num2;
        }
        return -1;
    }
};
