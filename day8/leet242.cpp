#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    int freq[26] = {0};

    for (char c : s)
        freq[c - 'a']++;

    for (char c : t)
    {
        if (--freq[c - 'a'] < 0)
            return false;
    }

    return true;
}

int main()
{
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "The strings are anagrams.\n";
    else
        cout << "The strings are not anagrams.\n";

    return 0;
}
