#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> result;
    if (s.size() < p.size())
        return result;

    vector<int> freq(26, 0);
    for (char c : p)
        ++freq[c - 'a'];

    int required = 0;
    for (int x : freq)
        if (x > 0)
            ++required;

    int left = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        int in = s[right] - 'a';
        if (--freq[in] == 0)
            --required;

        if (right - left + 1 > p.size())
        {
            int out = s[left++] - 'a';
            if (freq[out] == 0)
                ++required;
            ++freq[out];
        }

        if (right - left + 1 == p.size() && required == 0)
            result.push_back(left);
    }

    return result;
}

int main()
{
    string s, p;

    cout << "Enter the main string: ";
    cin >> s;

    cout << "Enter the pattern string: ";
    cin >> p;

    vector<int> indices = findAnagrams(s, p);

    if (indices.empty())
    {
        cout << "No anagrams of the pattern found.\n";
    }
    else
    {
        cout << "Starting indices of anagrams: ";
        for (int idx : indices)
            cout << idx << " ";
        cout << endl;
    }

    return 0;
}
