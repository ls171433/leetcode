#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> freq;
        for (int n : arr)
        {
            ++freq[n];
        }

        int result = -1;
        for (const auto &n_c : freq)
        {
            if (n_c.first == n_c.second)
            {
                result = n_c.first;
            }
        }

        return result;
    }
};