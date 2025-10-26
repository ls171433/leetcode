#include <vector>

using namespace std;

class Bank
{
public:
    int m_accounts;
    vector<long long> m_balances;

    Bank(vector<long long> &balance)
    {
        m_accounts = balance.size();
        m_balances.swap(balance);
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > m_accounts || account2 > m_accounts)
        {
            return false;
        }
        if (m_balances[account1 - 1] < money)
        {
            return false;
        }
        m_balances[account1 - 1] -= money;
        m_balances[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account > m_accounts)
        {
            return false;
        }
        m_balances[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account > m_accounts)
        {
            return false;
        }
        if (m_balances[account - 1] < money)
        {
            return false;
        }
        m_balances[account - 1] -= money;
        return true;
    }
};
