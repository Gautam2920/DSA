#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> last(128, -1);
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        left = max(left, last[s[right]] + 1);
        last[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    int result = lengthOfLongestSubstring(s);

    cout << "Length of the longest substring without repeating characters: "
         << result << endl;

    return 0;
}
