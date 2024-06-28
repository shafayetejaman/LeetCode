#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int>adjlist[N];
bool visited[N];
int level[N];

void bfs(int s, bool print)
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
        if (print) cout << parent << " ";

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

    // count the number of components
    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        cc++;
        bfs(i, false);

    }
    cout << cc << endl;

    // reset
    cc = 0;

    for (auto i = 0; i < N; i++)
    {
        visited[i] = 0;
    }

    // print the components

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        cc++;
        cout << "Component " << cc << " : ";
        bfs(i, true);
        cout << endl;
    }

    

    return 0;
}