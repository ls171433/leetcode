#include <iostream>
#include <vector>

using namespace std;

constexpr int BIG_DISTANCE = 200000;

class Solution
{
public:
    string pushDominoes(string dominoes) {
        if (dominoes.empty())
        {
            return dominoes;
        }

        vector<int> distance_left;
        vector<int> distance_right;
        distance_left.resize(dominoes.size());
        distance_right.resize(dominoes.size());

        distance_left[0] = (dominoes[0] == 'R' ? 0 : BIG_DISTANCE);
        for(size_t i = 1; i < dominoes.size(); ++i)
        {
            switch (dominoes[i])
            {
                case 'R':
                    distance_left[i] = 0;
                    break;
                case 'L':
                    distance_left[i] = BIG_DISTANCE;
                    break;
                case '.':
                    distance_left[i] = distance_left[i - 1] + 1;
                    break;
            }
        }

        distance_right[dominoes.size() - 1] = (dominoes[dominoes.size() - 1] == 'L' ? 0 : BIG_DISTANCE);
        for(size_t i = 1; i < dominoes.size(); ++i)
        {
            switch (dominoes[dominoes.size() - 1 - i])
            {
                case 'L':
                    distance_right[dominoes.size() - 1 - i] = 0;
                    break;
                case 'R':
                    distance_right[dominoes.size() - 1 - i] = BIG_DISTANCE;
                    break;
                case '.':
                    distance_right[dominoes.size() - 1 - i] = distance_right[dominoes.size() - i] + 1;
                    break;
            }
        }

        for(size_t i = 0; i < dominoes.size(); ++i)
        {
            if ((distance_left[i] >= BIG_DISTANCE && distance_right[i] >= BIG_DISTANCE) || distance_left[i] == distance_right[i])
            {
                dominoes[i] = '.';
            }
            else if (distance_left[i] > distance_right[i])
            {
                dominoes[i] = 'L';
            }
            else
            {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};

int main()
{
    string dominoes = ".L.R...LR..L..";
    auto result = Solution().pushDominoes(dominoes);
    cout << result << endl;
}
