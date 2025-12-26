#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();

    long long windowSum = 0;
    for (int i = 0; i < k; ++i)
        windowSum += nums[i];

    long long maxSum = windowSum;

    for (int i = k; i < n; ++i)
    {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return static_cast<double>(maxSum) / k;
}

int main()
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter value of k: ";
    cin >> k;

    if (k > n || k <= 0)
    {
        cout << "Invalid value of k\n";
        return 0;
    }

    double result = findMaxAverage(nums, k);
    cout << "Maximum average of subarray of size " << k << " is: " << result << endl;

    return 0;
}