#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int prevDay = st.top();
            st.pop();
            answer[prevDay] = i - prevDay;
        }
        st.push(i);
    }
    return answer;
}

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> temperatures(n);
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }

    vector<int> result = dailyTemperatures(temperatures);

    cout << "Days to wait for a warmer temperature:\n";
    for (int days : result)
    {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
