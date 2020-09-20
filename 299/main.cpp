#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int cows = 0, bulls = 0;
        int secret_cows[10] = {};
        int guess_cows[10] = {};
        for (size_t i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bulls;
            }
            else
            {
                ++(secret_cows[secret[i] - '0']);
                ++(guess_cows[guess[i] - '0']);
            }
        }

        for (size_t i = 0; i < 10; ++i)
        {
            cows += min(secret_cows[i], guess_cows[i]);
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }

    static int min(int lhs, int rhs)
    {
        return lhs > rhs ? rhs : lhs;
    }
};

int main()
{
    cout << Solution().getHint(string{"5283749"}, string{"4326590"}) << endl;
}
