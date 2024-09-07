#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 5;
long long int INF = 1e18;
long long int dis[N];
int level[N];
bool visited[N];
int parent[N];
vector<pii>adj[N];

int n, m;
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    dis[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({dis[s],s});
    while (!pq.empty())
    {
        pii f = pq.top();
        pq.pop();

        int selectedNode = f.second;

        if (visited[selectedNode]) continue;
        visited[selectedNode] = true;

        for (pii child : adj[selectedNode])
        {
            int Node = child.first;
            int edge_cost = child.second;

            if (dis[selectedNode] + edge_cost < dis[Node])
            {
                dis[Node] = dis[selectedNode] + edge_cost;
                pq.push({dis[Node],Node});
            
            }

        }


    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        // adj[v].push_back({u,w});
    }

    int s, t;
    cin >> s >> t;



    while (t--)
    {

        int d, w;
        cin >> d >> w;
        if (dis[d] <= w) cout << "YES" << endl;
        else cout << "NO" << endl;


        // cout<<dis[d]<<" ";

        // vector<pii>find;
        // find.push_back({d,w});
        // pii Nnode = find.front();
        // int nd= Nnode.first;
        // int nw=Nnode.second;
    }
    // cout<<"Destination : "<<level[d]<<endl;
    // int cur =d;
    // vector<int>path;
    // while(cur!= -1)
    // {
    //     path.push_back(cur);
    //     cur=parent[cur];
    // }
    // reverse(path.begin(),path.end());
    // cout<<"Shortest Path";
    // for(int Node : path)
    // {
    //     cout<<"->"<<Node;
    // }
    return 0;
}