#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int x1 = towers[0][0], x2 = towers[0][0];
        int y1 = towers[0][0], y2 = towers[0][0];
        for (const auto& tower : towers)
        {
            x1 = min(x1, tower[0]);
            x2 = max(x2, tower[0]);
            y1 = min(y1, tower[1]);
            y2 = max(y2, tower[1]);
        }
        size_t size = towers.size();
        int max_x = 0;
        int max_y = 0;
        int max_value = 0;
        for (size_t x = x1; x <= x2; ++x)
        {
        for (size_t y = y1; y <= y2; ++y)
        {
            int sum = 0;
            for(size_t i = 0; i < size; ++i)
            {
                int e = 0;
                int dx = towers[i][0] - x;
                int dy = towers[i][1] - y;
                int d2 = dx * dx + dy * dy;
                if (d2 <= radius * radius)
                {
                    e = towers[i][2] / (1 + sqrt(d2));
                }
                else
                {
                    e = 0;
                }
                sum += e;
            }
            if (sum > max_value)
            {
                max_x = x;
                max_y = y;
                max_value = sum;
            }
        }
        }
        vector<int> result;
        result.push_back(max_x);
        result.push_back(max_y);
        return result;
    }
};