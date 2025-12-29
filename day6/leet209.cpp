#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, sum = 0, minLen = INT_MAX;
    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size.\n";
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    int result = minSubArrayLen(target, nums);

    if (result == 0)
        cout << "No subarray found with sum >= target.\n";
    else
        cout << "Minimum length of subarray with sum >= target is: " << result << endl;

    return 0;
}