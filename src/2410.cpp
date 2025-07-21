#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int result = 0;
        int player_index = 0;
        int trainer_index = 0;
        while (player_index < players.size() && trainer_index < trainers.size())
        {
            if (players[player_index] <= trainers[trainer_index])
            {
                ++result;
                ++player_index;
            }
            ++trainer_index;
        }
        return result;
    }
};
