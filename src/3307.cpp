#include <vector>

using namespace std;

class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        int result = 0;
        int n = 0;
        --k;
        while (k)
        {
            result += (k % 2) * operations[n];
            k /= 2;
            ++n;
        }
        return 'a' + result % 26;
    }
};