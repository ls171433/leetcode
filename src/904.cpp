#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int fruit_1 = -1;
        int fruit_2 = -1;
        int count_1 = 0;
        int count_2 = 0;
        int direct_count = 0;
        int result = 0;

        for (int fruit : fruits)
        {
            if (fruit == fruit_1)
            {
                ++count_1;
                ++direct_count;
            }
            else if (fruit == fruit_2)
            {
                swap(fruit_1, fruit_2);
                swap(count_1, count_2);
                ++count_1;
                direct_count = 1;
            }
            else
            {
                result = max(result, count_1 + count_2);
                fruit_2 = fruit_1;
                count_2 = direct_count;
                fruit_1 = fruit;
                count_1 = 1;
                direct_count = 1;
            }
            // cout << fruit_1 << ' ' << count_1 << ' ' << fruit_2 << ' ' << count_2 << endl;
        }
        result = max(result, count_1 + count_2);
        return result;
    }
};
