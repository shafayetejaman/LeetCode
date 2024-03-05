#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{


    return 0;
}

class KthLargest
{
    priority_queue<int, vector<int>> pq;
    priority_queue<int, vector<int>, greater<int>> min;
    int k;
public:
    KthLargest(int k, vector<int>& nums)
    {
        for (const auto& i : nums)
        {
            pq.push(i);
        }

        this->k = k;

        while (!pq.empty() and k--)
        {
            min.push(pq.top());
            pq.pop();
        }
    }

    int add(int val)
    {
        if (min.size() < k)
        {
            min.push(val);
        }
        else if (val > min.top())
        {
            min.pop();
            min.push(val);
        }
        return min.top();
    }
};
class Solution
{
    priority_queue<int, vector<int>> pq;
public:
    int lastStoneWeight(vector<int>& stones)
    {
        for (const auto& i : stones)
        {
            pq.push(i);
        }
        while (pq.size() > 1)
        {
            int fir = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();

            int res = abs(fir - sec);
            pq.push(res);
        }
        if (pq.empty()) return 0;
        return pq.top();
    }
};

class Solution
{
public:
    typedef pair<int, vector<int>> piv;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<piv, vector<piv>, greater<piv>> min;

        for (const auto& i : points)
        {
            min.push({pow(i[0] - 0, 2) + pow(i[1] - 0, 2), i});
        }
        while (k--)
        {
            ans.push_back(min.top().second);
            min.pop();
        }
        return ans;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int>& v, int k)
    {
        priority_queue<int, vector<int>> pq;

        for (const auto& i : v)
        {
            pq.push(i);
        }
        while (k--)
        {
            pq.pop();
        }
        return pq.top();
    }
};