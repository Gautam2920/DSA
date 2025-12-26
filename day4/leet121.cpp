#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input\n";
        return 0;
    }

    vector<int> prices(n);
    cout << "Enter stock prices:\n";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int profit = maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}