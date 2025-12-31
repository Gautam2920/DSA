#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> groups;
    groups.reserve(strs.size());

    for (const string &s : strs)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        string key;
        key.reserve(52);
        for (int i = 0; i < 26; i++)
        {
            key.push_back('#');
            key.push_back(freq[i]);
        }

        groups[key].push_back(s);
    }

    vector<vector<string>> result;
    result.reserve(groups.size());
    for (auto &it : groups)
        result.push_back(move(it.second));

    return result;
}

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<string> strs(n);
    cout << "Enter the strings (lowercase letters only):\n";
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    vector<vector<string>> result = groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (const auto &group : result)
    {
        cout << "[ ";
        for (const string &word : group)
            cout << word << " ";
        cout << "]\n";
    }

    return 0;
}