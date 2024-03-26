#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(int k) {
        return sqrt(k - 0.3) * 2 - 1;
    }
};

int main()
{
    int k = 11;
    auto result = Solution().minOperations(k);
    cout << result << endl;
}

/*
1   1   1
2   1.5 2.25
3   2   4
4   2.5 6.25
5   3   9
6   3.5 12.25
*/