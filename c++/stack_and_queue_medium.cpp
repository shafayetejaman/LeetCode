#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> que;
        for (auto i = 1; i <= n; i++)
        {
            que.push(i);
        }

        while (que.size() > 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                que.push(que.front());
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }
};
