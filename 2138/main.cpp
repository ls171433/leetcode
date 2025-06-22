#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int size = s.size();
        int count = size / k;
        vector<string> result;
        result.reserve(count + 1);
        for (size_t i = 0; i < count; ++i)
        {
            result.emplace_back(&s[i * k], &s[(i + 1) * k]);
        }
        if (size % k != 0)
        {
            result.emplace_back(&s[count * k], &s[size]);
            result.back().reserve(k + 1);
            result.back().append(k - size % k, fill);
        }
        return result;
    }
};