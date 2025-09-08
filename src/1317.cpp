#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int result = 0;
        int temp = n;
        int base = 1;
        while (temp)
        {
            // cout << temp << endl;
            // cout << base << endl;
            if (temp % 10 == 1 && temp >= 10)
            {
                result += base * 2;
                temp -= 2;
            }
            else
            {
                result += base;
                temp -= 1;
            }
            temp /= 10;
            base *= 10;
        }
        return {result, n - result};
    }
};

int main()
{
    Solution s;
    auto result = s.getNoZeroIntegers(1010);
    for (auto num : result)
    {
        cout << num << endl;
    }
}
