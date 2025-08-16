class Solution
{
public:
    int maximum69Number(int num)
    {
        int base = 1;
        int result = num;
        while (base < num)
        {
            if ((num / base) % 10 == 6)
            {
                result = num + 3 * base;
            }
            base *= 10;
        }
        return result;
    }
};

