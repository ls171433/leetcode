#include <set>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class MovieRentingSystem
{
public:
    unordered_map<int, unordered_map<int, int>> m_shop_movie_price;
    unordered_map<int, set<pair<int, int>>> m_unrented_movie_price_shop;
    map<int, set<pair<int, int>>> m_rented_price_shop_movie;

    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (const auto &entry : entries)
        {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            m_shop_movie_price[shop][movie] = price;
            m_unrented_movie_price_shop[movie].emplace(price, shop);
        }
    }

    vector<int> search(int movie)
    {
        vector<int> result;
        for (const auto &[price, shop] : m_unrented_movie_price_shop[movie])
        {
            result.push_back(shop);
            if (result.size() == 5)
            {
                break;
            }
        }
        return result;
    }

    void rent(int shop, int movie)
    {
        int price = m_shop_movie_price[shop][movie];
        m_unrented_movie_price_shop[movie].erase({price, shop});
        m_rented_price_shop_movie[price].emplace(shop, movie);
    }

    void drop(int shop, int movie)
    {
        int price = m_shop_movie_price[shop][movie];
        m_unrented_movie_price_shop[movie].emplace(price, shop);
        m_rented_price_shop_movie[price].erase({shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> result;
        for (const auto &[price, shop_movie_set] : m_rented_price_shop_movie)
        {
            for (const auto &[shop, movie] : shop_movie_set)
            {
                result.push_back({shop, movie});
                if (result.size() == 5)
                {
                    return result;
                }
            }
        }
        return result;
    }
};
