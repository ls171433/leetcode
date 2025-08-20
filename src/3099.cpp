class Solution
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        if (x == 100)
        {
            return 1;
        }
        if (x < 10)
        {
            return x;
        }
        int h = x / 10 + x % 10;
        if (x % h == 0)
        {
            return h;
        }
        return -1;
    }
};
