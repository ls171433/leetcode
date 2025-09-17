#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class FoodRatings
{
public:
    struct compare
    {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const
        {
            if (a.first != b.first)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };

    unordered_map<string, pair<string, int>> m_food_cuisine_ratings;
    unordered_map<string, set<pair<int, string>, compare>> m_cuisine_ratings_foods;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; ++i)
        {
            m_food_cuisine_ratings[foods[i]] = {cuisines[i], ratings[i]};
            m_cuisine_ratings_foods[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        auto &[cuisine, oldRating] = m_food_cuisine_ratings[food];
        m_cuisine_ratings_foods[cuisine].erase({oldRating, food});
        m_cuisine_ratings_foods[cuisine].insert({newRating, food});
        oldRating = newRating;
    }

    string highestRated(string cuisine)
    {
        return m_cuisine_ratings_foods[cuisine].begin()->second;
    }
};
