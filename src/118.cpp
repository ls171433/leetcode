#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result[0] = {1};
        for (int i = 1; i < numRows; ++i) {
            auto& previous_row = result[i - 1];
            auto& current_row = result[i];
            current_row.resize(i + 1);
            current_row[0] = current_row[i] = 1;
            for (int j = 1; j < i; ++j) {
                current_row[j] = previous_row[j - 1] + previous_row[j];
            }  
        }
        return result;
    }
};
