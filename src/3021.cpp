
class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        return (static_cast<long long>(n / 2) * static_cast<long long>((m + 1) / 2)) +
               (static_cast<long long>(m / 2) * static_cast<long long>((n + 1) / 2));
    }
};
