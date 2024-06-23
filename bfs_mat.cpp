#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int>adjlist[N];
bool visited[N];
int level[N];

vector<vector<int>> cc;

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    //cout<<"visited S ="<<s<<endl;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // print the nodes of the components
        cc.back().push_back(parent);

        for (int child : adjlist[parent])
        {
            if (visited[child]) continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[parent] + 1;

        }
    }

}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }


    // code for connect components :

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        
        cc.push_back({});
        bfs(i);
    }

    cout << cc.size() << endl;

    int count = 1;

    for (auto v : cc)
    {
        cout << "Component " << count++ << " : ";
        
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}