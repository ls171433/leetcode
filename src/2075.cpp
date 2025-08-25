#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        int n = encodedText.size() / rows;

        string result;
        result.reserve(encodedText.size());
        int column_end = min(n, n - rows + 2);
        for (int column = 0; column < column_end; ++column)
        {
            for (int row = 0; row < rows; ++row)
            {
                int index = row * n + (column + row) % n;
                result.push_back(encodedText[index]);
            }
        }

        auto size = result.find_last_not_of(' ');
        if (size != string::npos)
        {
            result.resize(size + 1);
        }
        return result;
    }
};
