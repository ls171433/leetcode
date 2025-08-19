#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || n >= k + maxPts - 1)
        {
            return 1.0;
        }

        vector<double> rate(maxPts, 0.0);
        rate[0] = 1.0;

        int i = 1;
        double sum = 1.0;
        for (; i < k; ++i)
        {
            double temp =  sum / maxPts;
            sum += temp;
            if (i - maxPts >= 0)
            {
                sum -= rate[i % maxPts];
            }
            rate[i % maxPts] = temp;
        }

        double result = 0.0;
        for (; i <= n; ++i)
        {
            result += sum / maxPts;
            if (i - maxPts >= 0)
            {
                sum -= rate[i % maxPts];
            }
        }

        return result;
    }
};
