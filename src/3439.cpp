#include <vector>

using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        int sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += endTime[i] - startTime[i];
        }

        if (n == k)
        {
            return eventTime - 0 -sum;
        }

        int result = startTime[k] - 0 - sum;

        for (int i = 0; i + k + 1 < n; ++i)
        {
            sum += endTime[i + k] - startTime[i + k];
            sum -= endTime[i] - startTime[i];
            result = max(result, startTime[i + k + 1] - endTime[i] - sum);
        }
        sum += endTime[n - 1] - startTime[n - 1];
        sum -= endTime[n - k - 1] - startTime[n - k - 1];
        result = max(result, eventTime - endTime[n - k - 1] - sum);

        return result;
    }
};
