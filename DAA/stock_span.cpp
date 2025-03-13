#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> calculateSpan(int price[], int n);

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    calculateSpan(price, n);
    return 0;
}

vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans;
    stack<int> stack;

    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && price[stack.top()] <= price[i])
            stack.pop();

        int span = stack.empty() ? i + 1 : i - stack.top();
        ans.push_back(span);
        stack.push(i);
    }

    cout << "Span: ";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return ans;
}