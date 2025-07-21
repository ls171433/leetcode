#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> results;
        size_t size = digits.size();
        for(size_t i = 0; i < size; ++i)
        {
            if (digits[i] == 0)
            {
                continue;
            }
            for(size_t j = 0; j < size; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                for(size_t k = 0; k < size; ++k)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    if (digits[k] % 2 != 0)
                    {
                        continue;
                    }
                    results.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        return vector<int>{results.begin(), results.end()};
    }
};

int main()
{
    vector<int> digits = {1, 2, 3, 4};
    auto results = Solution().findEvenNumbers(digits);
    for (auto& result : results)
    {
        cout << result << endl;
    }
}
