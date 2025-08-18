#include <cstdio>
#include <vector>

using namespace std;

struct Rational
{
    int numerator;
    int denominator;
    Rational(int n, int d) : numerator(n), denominator(d) {}
    Rational(int n) : numerator(n), denominator(1) {}
    bool operator==(const Rational &other) const
    {
        return numerator * other.denominator == denominator * other.numerator;
    }
    bool operator!=(const Rational &other) const
    {
        return !(*this == other);
    }
};

Rational operator+(const Rational &a, const Rational &b)
{
    return {a.numerator * b.denominator + a.denominator * b.numerator, a.denominator * b.denominator};
}

Rational operator-(const Rational &a, const Rational &b)
{
    return {a.numerator * b.denominator - a.denominator * b.numerator, a.denominator * b.denominator};
}

Rational operator*(const Rational &a, const Rational &b)
{
    return {a.numerator * b.numerator, a.denominator * b.denominator};
}

Rational operator/(const Rational &a, const Rational &b)
{
    return {a.numerator * b.denominator, a.denominator * b.numerator};
}

class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<Rational> rational_cards;
        rational_cards.reserve(4);
        for (int card : cards)
        {
            rational_cards.emplace_back(card);
        }
        return judgePoint24(rational_cards);
    }

    bool judgePoint24(vector<Rational> &cards)
    {
        if (cards.size() == 1)
        {
            return cards[0] == 24;
        }

        for (int i = 0; i + 1 < cards.size(); ++i)
        {
            for (int j = i + 1; j < cards.size(); ++j)
            {
                vector<Rational> next_cards;
                next_cards.reserve(cards.size() - 1);
                for (int k = 0; k < cards.size(); ++k)
                {
                    if (k != i && k != j)
                    {
                        next_cards.push_back(cards[k]);
                    }
                }

                // +
                next_cards.push_back(cards[i] + cards[j]);
                if (judgePoint24(next_cards))
                {
                    return true;
                }
                next_cards.pop_back();

                // -
                next_cards.push_back(cards[i] - cards[j]);
                if (judgePoint24(next_cards))
                {
                    return true;
                }
                next_cards.pop_back();

                // -
                next_cards.push_back(cards[j] - cards[i]);
                if (judgePoint24(next_cards))
                {
                    return true;
                }
                next_cards.pop_back();

                // *
                next_cards.push_back(cards[i] * cards[j]);
                if (judgePoint24(next_cards))
                {
                    return true;
                }
                next_cards.pop_back();

                // /
                if (cards[j] != 0)
                {
                    next_cards.push_back(cards[i] / cards[j]);
                    if (judgePoint24(next_cards))
                    {
                        return true;
                    }
                    next_cards.pop_back();
                }

                // /
                if (cards[i] != 0)
                {
                    next_cards.push_back(cards[j] / cards[i]);
                    if (judgePoint24(next_cards))
                    {
                        return true;
                    }
                    next_cards.pop_back();
                }
            }
        }

        return false;
    }
};

int main()
{
    constexpr int min = 1, max = 13;
    for (int i = min; i <= max; ++i)
    {
        for (int j = i; j <= max; ++j)
        {
            for (int k = j; k <= max; ++k)
            {
                for (int l = k; l <= max; ++l)
                {
                    vector<int> cards = {i, j, k, l};
                    Solution solution;
                    if (solution.judgePoint24(cards))
                    {
                        printf("Cards: %d %d %d %d can make 24\n", i, j, k, l);
                    }
                    else
                    {
                        printf("Cards: %d %d %d %d cannot make 24\n", i, j, k, l);
                    }
                }
            }
        }
    }
}
