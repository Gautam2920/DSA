#include <iostream>
#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int maxWealth = 0;
    for (auto &row : accounts)
    {
        int wealth = 0;
        for (int money : row)
        {
            wealth += money;
        }
        maxWealth = max(maxWealth, wealth);
    }
    return maxWealth;
}

int main()
{
    int customers, banks;

    cout << "Enter number of customers: ";
    cin >> customers;

    cout << "Enter number of banks per customer: ";
    cin >> banks;

    vector<vector<int>> accounts(customers, vector<int>(banks));

    cout << "\nEnter the money in each bank for every customer:\n";

    for (int i = 0; i < customers; i++)
    {
        cout << "Customer " << i + 1 << ": ";
        for (int j = 0; j < banks; j++)
        {
            cin >> accounts[i][j];
        }
    }

    int result = maximumWealth(accounts);

    cout << "\nMaximum wealth among all customers is: " << result << endl;

    return 0;
}
