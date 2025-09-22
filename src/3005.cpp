#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> frequency;
        int max_frequency = 0;

        for (int num : nums)
        {
            frequency[num]++;
            max_frequency = max(max_frequency, frequency[num]);
        }

        int result = 0;
        for (const auto &pair : frequency)
        {
            if (pair.second == max_frequency)
            {
                result += max_frequency;
            }
        }

        return result;
    }
};
