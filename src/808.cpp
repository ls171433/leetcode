#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    double soupServings(int n)
    {
        int new_n = (n + 24) / 25;
        if (new_n > 200)
        {
            return 1.0;
        }

        unsigned long long full = 1ull << 63;
        unsigned long long result = 0;
        int round = 0;
        unordered_map<int, unsigned long long> current;
        unordered_map<int, unsigned long long> temp;
        current[0] = full;
        while (!current.empty())
        {
            temp.clear();
            for (auto &[a, p] : current)
            {
                if (p == 0)
                {
                    continue;
                }

                int b = round * 4 - a;
                // cout << a << ' ' << b << ' ' << p << endl;
                if (a >= new_n && b >= new_n)
                {
                    result += p / 2;
                }
                else if (a >= new_n)
                {
                    result += p;
                }
                else if (b >= new_n)
                {
                    continue;
                }
                else if ((new_n - a) * 3 < (new_n - b))
                {
                    result += p;
                }
                else
                {
                    temp[a + 4] += p / 4;
                    temp[a + 3] += p / 4;
                    temp[a + 2] += p / 4;
                    temp[a + 1] += p / 4;
                }
            }
            swap(current, temp);
            ++round;
        }
        return static_cast<double>(result) / static_cast<double>(full);
    }
};
