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
        int current_count = 0;
        int direct_count = 0;
        int result = 0;

        for (int fruit : fruits)
        {
            if (fruit == fruit_1)
            {
                ++current_count;
                ++direct_count;
            }
            else if (fruit == fruit_2)
            {
                swap(fruit_1, fruit_2);
                ++current_count;
                direct_count = 1;
            }
            else
            {
                result = max(result, current_count);
                fruit_2 = fruit_1;
                fruit_1 = fruit;
                current_count = direct_count + 1;
                direct_count = 1;
            }
            // cout << fruit_1 << ' ' << fruit_2 << ' ' << current_count << endl;
        }
        result = max(result, current_count);
        return result;
    }
};
