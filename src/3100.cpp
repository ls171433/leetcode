
class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int numExchanged = 0;
        int numDrunk = numBottles;
        while (numExchanged + numExchange <= numDrunk)
        {
            numExchanged += numExchange;
            numDrunk += 1;
            ++numExchange;
        }
        return numDrunk;
    }
};
