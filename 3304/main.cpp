class Solution
{
public:
    char kthCharacter(int k)
    {
        char c = 'a';
        k -= 1;
        while (k)
        {
            c += k % 2;
            k /= 2;
        }
        return c;
    }
};