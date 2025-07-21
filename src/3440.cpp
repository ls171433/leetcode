#include <vector>

using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();

        int max_gap_before = 0;
        int max_gap_after = 0;
        int result = 0;

        result = (startTime[1] - 0) - (endTime[0] - startTime[0]);
        max_gap_before = startTime[0] - 0;
        max_gap_after = eventTime - endTime[n - 1];
        for (int i = 0; i + 2 < n; ++i)
        {
            if (max_gap_before >= (endTime[i + 1] - startTime[i + 1]))
            {
                result = max(result, (startTime[i + 2] - endTime[i]));
            }
            else
            {
                result = max(result, (startTime[i + 2] - endTime[i]) - (endTime[i + 1] - startTime[i + 1]));
            }
            if (max_gap_after >= (endTime[n - i - 2] - startTime[n - i - 2]))
            {
                result = max(result, (startTime[n - i - 1] - endTime[n - i - 3]));
            }
            max_gap_before = max(max_gap_before, startTime[i + 1] - endTime[i]);
            max_gap_after = max(max_gap_after, startTime[n - i - 1] - endTime[n - i - 2]);
        }
        if (max_gap_before >= (endTime[n - 1] - startTime[n - 1]))
        {
            result = max(result, (eventTime - endTime[n - 2]));
        }
        else
        {
            result = max(result, (eventTime - endTime[n - 2]) - (endTime[n - 1] - startTime[n - 1]));
        }
        if (max_gap_after >= (endTime[0] - startTime[0]))
        {
            result = max(result, (startTime[1] - 0));
        }

        return result;
    }
};