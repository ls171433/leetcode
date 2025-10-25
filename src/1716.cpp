class Solution
{
public:
    int totalMoney(int n)
    {
        int weeks = n / 7;
        int days = n % 7;

        return (28 + 28 + (weeks - 1) * 7) * weeks / 2 + days * (weeks + 1) + (days * (days - 1)) / 2;
    }
};
