#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
            return {left + 1, right + 1};

        sum > target ? --right : ++left;
    }
    return {};
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 1)
    {
        cout << "Array must have at least two elements.\n";
        return 0;
    }

    vector<int> numbers(n);
    cout << "Enter the elements (in sorted order):\n";
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = twoSum(numbers, target);

    if (!result.empty())
        cout << "Indices (1-based): " << result[0] << " " << result[1] << endl;
    else
        cout << "No pair found with the given target.\n";

    return 0;
}