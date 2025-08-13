#include <vector>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        vector<signed char> digits;
        digits.reserve(9);
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }

        signed char selected_large = digits.back();
        signed char changed_large = 9;
        signed char selected_small = digits.back();
        signed char changed_small = 1;
        int large = 0;
        int small = 0;
        while (!digits.empty())
        {
            large *= 10;
            if (selected_large == 9 && digits.back() != 9)
            {
                selected_large = digits.back();
            }
            if (digits.back() == selected_large)
            {
                large += changed_large;
            }
            else
            {
                large += digits.back();
            }

            small *= 10;
            if (selected_small == 1 && digits.back() != 0 && digits.back() != 1)
            {
                selected_small = digits.back();
                changed_small = 0;
            }
            if (digits.back() == selected_small)
            {
                small += changed_small;
            }
            else
            {
                small += digits.back();
            }

            digits.pop_back();
        }
        return large - small;
    }
};
