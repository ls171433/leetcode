#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator0, int denominator0)
    {
        long long numerator = numerator0;
        long long denominator = denominator0;
        if (numerator == 0)
        {
            return "0";
        }

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        string result;
        if (numerator < 0)
        {
            result.push_back('-');
            numerator = -numerator;
        }

        result += to_string(numerator / denominator);
        numerator %= denominator;
        if (numerator == 0)
        {
            return result;
        }
        result.push_back('.');

        string decimal;
        int position = -1;
        int index = 0;
        unordered_map<long long, int> remains;
        while (numerator != 0)
        {
            if (remains.count(numerator))
            {
                position = remains[numerator];
                break;
            }
            remains[numerator] = index++;

            numerator *= 10;
            decimal.push_back(numerator / denominator + '0');
            numerator %= denominator;
        }

        if (position != -1)
        {
            result.reserve(result.size() + decimal.size() + 2);
            for (int i = 0; i < position; ++i)
            {
                result.push_back(decimal[i]);
            }
            result.push_back('(');
            for (int i = position; i < decimal.size(); ++i)
            {
                result.push_back(decimal[i]);
            }
            result.push_back(')');
            return result;
        }
        else
        {
            result += decimal;
        }
        return result;
    }
};
