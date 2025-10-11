#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        sort(power.begin(), power.end());
        int power_1 = -2;
        int power_2 = -1;
        long long damage_0 = 0;
        long long damage_1 = 0;
        long long damage_2 = 0;
        for (int p : power)
        {
            if (p == power_2)
            {
                damage_2 += p;
                continue;
            }

            int new_power = p;
            long long new_damage = 0;
            if (p - power_2 >= 3)
            {
                new_damage = max(max(damage_0, damage_1), damage_2) + p;
            }
            else if (p - power_1 >= 3)
            {
                new_damage = max(damage_0, damage_1) + p;
            }
            else
            {
                new_damage = damage_0 + p;
            }

            power_1 = power_2;
            power_2 = new_power;
            damage_0 = max(damage_0, damage_1);
            damage_1 = damage_2;
            damage_2 = new_damage;

            // cout << '-' << ' ' << power_1 << ' ' << power_2 << endl;
            // cout << damage_0 << ' ' << damage_1 << ' ' << damage_2 << endl;
        }

        return max(max(damage_0, damage_1), damage_2);
    }
};
