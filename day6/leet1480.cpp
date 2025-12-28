#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input\n";
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> result = runningSum(nums);

    cout << "Running sum array:\n";
    for (int x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}