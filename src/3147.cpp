#include <vector>

using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        int result = INT_MIN;
        for (int i = 0; i < k && i < n; ++i)
        {
            int max_energy = 0;
            for (int j = i; j < n; j += k)
            {
                max_energy += energy[n - 1 - j];
                result = max(result, max_energy);
            }
        }
        return result;
    }
};
