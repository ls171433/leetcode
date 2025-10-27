#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int previous = 0;
        int result = 0;

        for (const string &row : bank)
        {
            int current = 0;
            for (char cell : row)
            {
                if (cell == '1')
                {
                    ++current;
                }
            }

            if (current > 0)
            {
                result += previous * current;
                previous = current;
            }
        }

        return result;
    }
};
