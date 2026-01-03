#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    string result;
    for (char ch : s)
    {
        if (!result.empty() && result.back() == ch)
            result.pop_back();
        else
            result.push_back(ch);
    }
    return result;
}

int main()
{
    string input;

    cout << "Enter the string: ";
    cin >> input;

    string output = removeDuplicates(input);

    cout << "String after removing adjacent duplicates: " << output << endl;

    return 0;
}
