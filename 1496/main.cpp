#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        set<int> passed_positions;
        int position = 0;

        passed_positions.insert(position);
        for (char c : path)
        {
            switch (c)
            {
            case 'N':
                ++position;
                break;
            case 'S':
                --position;
                break;
            case 'E':
                position += 65536;
                break;
            case 'W':
                position -= 65536;
                break;
            }

            if (passed_positions.find(position) != passed_positions.end())
            {
                return true;
            }

            passed_positions.insert(position);
        }

        return false;
    }
};

int main()
{
    cout << Solution().isPathCrossing(string{"NSEW"}) << endl;
}
