#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixCount;
    prefixCount.reserve(nums.size());
    prefixCount[0] = 1;

    int sum = 0, count = 0;

    for (int num : nums)
    {
        sum += num;
        count += prefixCount[sum - k];
        prefixCount[sum]++;
    }

    return count;
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

    int k;
    cout << "Enter target sum (k): ";
    cin >> k;

    int result = subarraySum(nums, k);

    cout << "Number of subarrays with sum equal to " << k << " is: "
         << result << endl;

    return 0;
}
