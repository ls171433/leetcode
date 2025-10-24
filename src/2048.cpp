#include <array>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        constexpr array<int, 110> beautiful_numbers = {
            1,
            22,
            122,
            212,
            221,
            333,
            1333,
            3133,
            3313,
            3331,
            4444,
            14444,
            22333,
            23233,
            23323,
            23332,
            32233,
            32323,
            32332,
            33223,
            33232,
            33322,
            41444,
            44144,
            44414,
            44441,
            55555,
            122333,
            123233,
            123323,
            123332,
            132233,
            132323,
            132332,
            133223,
            133232,
            133322,
            155555,
            212333,
            213233,
            213323,
            213332,
            221333,
            223133,
            223313,
            223331,
            224444,
            231233,
            231323,
            231332,
            232133,
            232313,
            232331,
            233123,
            233132,
            233213,
            233231,
            233312,
            233321,
            242444,
            244244,
            244424,
            244442,
            312233,
            312323,
            312332,
            313223,
            313232,
            313322,
            321233,
            321323,
            321332,
            322133,
            322313,
            322331,
            323123,
            323132,
            323213,
            323231,
            323312,
            323321,
            331223,
            331232,
            331322,
            332123,
            332132,
            332213,
            332231,
            332312,
            332321,
            333122,
            333212,
            333221,
            422444,
            424244,
            424424,
            424442,
            442244,
            442424,
            442442,
            444224,
            444242,
            444422,
            515555,
            551555,
            555155,
            555515,
            555551,
            666666,
            1224444,
        };
        return *upper_bound(beautiful_numbers.begin(), beautiful_numbers.end(), n);
    }
};

class Solution_2
{
public:
    int nextBeautifulNumber(int n)
    {
        vector<int> beautiful_numbers = generate_beautiful_numbers();
        return *upper_bound(beautiful_numbers.begin(), beautiful_numbers.end(), n);
    }

    static vector<int> generate_beautiful_numbers()
    {
        vector<int> result;
        vector_push_back_vector(result, generate_numbers_0({1}));
        vector_push_back_vector(result, generate_numbers_0({2}));
        vector_push_back_vector(result, generate_numbers_0({3}));
        vector_push_back_vector(result, generate_numbers_0({4}));
        vector_push_back_vector(result, generate_numbers_0({5}));
        vector_push_back_vector(result, generate_numbers_0({6}));
        vector_push_back_vector(result, generate_numbers_0({1, 2}));
        vector_push_back_vector(result, generate_numbers_0({1, 3}));
        vector_push_back_vector(result, generate_numbers_0({1, 4}));
        vector_push_back_vector(result, generate_numbers_0({1, 5}));
        vector_push_back_vector(result, generate_numbers_0({2, 3}));
        vector_push_back_vector(result, generate_numbers_0({2, 4}));
        vector_push_back_vector(result, generate_numbers_0({1, 2, 3}));
        result.push_back(1224444);
        sort(result.begin(), result.end());
        // for (int &number : result)
        // {
        //     cout << number << ',' << endl;
        // }
        return result;
    }

    static vector<int> generate_numbers_0(const vector<int> &digits)
    {
        return generate_numbers(digits, digits);
    }

    static vector<int> generate_numbers(const vector<int> &digits, const vector<int> &counts)
    {
        vector<int> result;
        int total_count = 0;
        for (size_t i = 0; i < digits.size(); ++i)
        {
            total_count += counts[i];
            if (counts[i] > 0)
            {
                vector<int> new_counts = counts;
                new_counts[i]--;
                vector<int> sub_numbers = generate_numbers(digits, new_counts);
                for (int sub_number : sub_numbers)
                {
                    result.push_back(sub_number * 10 + digits[i]);
                }
            }
        }
        if (total_count == 0)
        {
            result.push_back(0);
        }
        return result;
    }

    static void vector_push_back_vector(vector<int> &a, const vector<int> &b)
    {
        for (int number : b)
        {
            a.push_back(number);
        }
    }
};
