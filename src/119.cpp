#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row;
        row.reserve(rowIndex + 1);

        long long temp = 1;
        row.push_back(temp);
        for (size_t i = 1; i <= rowIndex; ++i)
        {
            temp *= (rowIndex + 1 - i);
            temp /= i;
            row.push_back(temp);
        }

        return row;
    }
};

int main()
{
    auto row = Solution{}.getRow(20);
    for (const auto &value : row)
    {
        cout << value << ' ';
    }
    cout << endl;
}
