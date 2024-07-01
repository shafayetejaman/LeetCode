#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adjlist[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    visited[s] = true;
    queue<int>q;
    q.push(s);
    level[s] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int c = 0; c < adjlist[p].size();c++)
        {
            int child = adjlist[p][c];
            if (visited[child])continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[p] + 1;
        }
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        level[i] = -1;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bfs(0);
    int target;
    cin >> target;
    vector<int>kyl;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == target)
        {
            kyl.push_back(i);
        }
    }
    if (kyl.empty())
    {
        cout << -1;
    }
    else
    {
        sort(kyl.begin(), kyl.end());
        for (int i = 0; i < kyl.size(); i++)
        {
            cout << kyl[i] << " ";
        }
    }
    return 0;
}