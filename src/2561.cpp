#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        map<int, int> count_diff;
        for (int num1 : basket1)
        {
            count_diff[num1]++;
        }
        for (int num2 : basket2)
        {
            count_diff[num2]--;
        }

        int min_num = count_diff.begin()->first;

        int sum = 0;
        for (auto &[num, count] : count_diff)
        {
            if (count % 2 != 0)
            {
                return -1;
            }
            count = abs(count) / 2;
            sum += count;
            // cout << num << ' ' << count << endl;
        }
        sum /= 2;
        // cout << sum << endl;

        long long result = 0;
        for (const auto &[num, count] : count_diff)
        {
            long long num_temp = min(min_num * 2, num);
            if (count < sum)
            {
                result += num_temp * count;
                sum -= count;
            }
            else
            {
                result += num_temp * sum;
                sum = 0;
                break;
            }
        }
        return result;
    }
};