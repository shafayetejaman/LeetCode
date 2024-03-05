#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class MinStack
{
public:
    int stack[3 * 10000];
    int stackmin[3 * 10000];
    int top_ele = -1;

    MinStack()
    {}

    void push(int val)
    {
        top_ele++;
        stack[top_ele] = val;
        if (top_ele > 0)
            stackmin[top_ele] = min(val, stackmin[top_ele - 1]);
        else
            stackmin[top_ele] = val;
    }

    void pop()
    {
        top_ele--;
    }

    int top()
    {
        return stack[top_ele];
    }

    int getMin()
    {
        return stackmin[top_ele];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        int ans;
        stack<int> st;
        for (const auto& i : tokens)
        {
            if (i != "+" && i != "-" && i != "*" && i != "/")

            {
                st.push(stoi(i));
            }
            else if (st.size() > 1)
            {
                int a, b;
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                if (i == "+")
                    st.push(a + b);
                else if (i == "-")
                    st.push(a - b);
                else if (i == "*")
                    st.push(a * b);
                else if (i == "/")
                    st.push(a / b);
            }
        }
        return st.top();
    }
};

class Solution
{
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n)
    {
        pre(n, n, "");
        return ans;
    }
    void pre(int open, int close, string s)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }

        if (open > 0)
        {
            pre(open - 1, close, s + '(');
        }
        if (close > 0 && open > close)
        {
            pre(open, close - 1, s + ')');
        }
    }
};

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& tem)
    {
        stack<int> st;
        vector<int> ans(tem.size());

        for (auto i = 0; i < tem.size(); i++)
        {
            if (!st.empty() && tem[st.top()] < tem[i])
            {
                ans[st.top()] = i - st.top();
            }
            st.pop();
            st.push(i);
        }
        return ans;
    }
};
class Solution
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n = position.size();

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end(), [](pair<int, double>& a, pair<int, double>& b) { return a.first < b.first; });

        double maxTime = 0.0;
        int result = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (cars[i].second > maxTime)
            {
                cars[i].second = maxTime;
                result++;
            }
        }

        return result;
    }
};
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int count = 0;
        for (const auto& i : s)
        {
            if (i == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    count++;
                }
            }
        }
        return count + st.size();
    }
};
class Solution
{
public:
    int minInsertions(string s)
    {
        stack<char> st;
        bool prev = false;
        bool prevF = false;
        int count = 0;

        for (const auto& i : s)
        {
            if (i == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    if (prev)
                    {
                        st.pop();
                        prev = false;
                    }
                    else
                    {
                        prev = true;
                    }
                }
                else
                {
                    if (prevF)
                    {

                        count++;
                    }
                    else
                    {
                        prevF = true;
                    }
                }
            }
        }
        return st.size() + count;
    }
};
class Solution
{
public:
    string removeStars(string s)
    {
        string ans;
        for (auto i : s)
        {
            if (i == '*')
            {
                if (!ans.empty())
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans += i;
            }
        }
        return ans;
    }
};