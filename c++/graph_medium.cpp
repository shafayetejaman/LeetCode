#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{


    return 0;
}

class Solution
{
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    vector<vi> vis;
    vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    int numIslands(vector<vector<char>>& graph)
    {
        vis.resize(graph.size(), vi(graph[0].size(), false));
        int c = 0;
        for (auto i = 0; i < graph.size(); i++)
        {
            for (auto j = 0; j < graph[0].size(); j++)
            {
                if (vis[i][j] or graph[i][j] == '0') continue;
                bfs(i, j, graph);
                c++;
            }
        }
        return c;
    }
    void bfs(int si, int sj, vector<vector<char>>& graph)
    {
        queue<pii> que;
        que.push({si, sj});
        vis[si][sj] = true;

        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;

            que.pop();

            for (const auto& k : dir)
            {
                int ni = k.first + i;
                int nj = k.second + j;
                if (valid(ni, nj, graph) and !vis[ni][nj])
                {
                    que.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
        }
    }
    bool valid(int i, int j, vector<vector<char>>& graph)
    {
        return (i >= 0 and i < graph.size() and j >= 0 and j < graph[0].size() and graph[i][j] == '1');
    }

};

class Solution
{
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    vector<vi> vis;
    vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int c;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& graph, int si, int sj, int color)
    {
        c = graph[si][sj];
        vis.resize(graph.size(), vi(graph[0].size(), false));
        bfs(si, sj, graph, color);
        return graph;
    }


    void bfs(int si, int sj, vector<vector<int>>& graph, int color)
    {
        queue<pii> que;
        que.push({si, sj});
        vis[si][sj] = true;

        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;
            graph[i][j] = color;

            que.pop();

            for (const auto& k : dir)
            {
                int ni = k.first + i;
                int nj = k.second + j;
                if (valid(ni, nj, graph) and !vis[ni][nj])
                {
                    que.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
        }
    }
    bool valid(int i, int j, vector<vector<int>>& graph)
    {
        return (i >= 0 and i < graph.size() and j >= 0 and j < graph[0].size() and graph[i][j] == c);
    }
};

class Solution
{
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    vector<vi> vis;
    vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& graph)
    {
        vis.resize(graph.size(), vi(graph[0].size(), false));
        int m = 0;
        for (auto i = 0; i < graph.size(); i++)
        {
            for (auto j = 0; j < graph[0].size(); j++)
            {
                if (vis[i][j] or graph[i][j] == 0) continue;
                m = max(m, bfs(i, j, graph));

            }
        }
        return m;
    }

    int bfs(int si, int sj, vector<vector<int>>& graph)
    {
        queue<pii> que;
        que.push({si, sj});
        vis[si][sj] = true;
        int c = 0;

        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;

            que.pop();
            c++;


            for (const auto& k : dir)
            {
                int ni = k.first + i;
                int nj = k.second + j;
                if (valid(ni, nj, graph) and !vis[ni][nj])
                {
                    que.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
        }
        return c;
    }
    bool valid(int i, int j, vector<vector<int>>& graph)
    {
        return (i >= 0 and i < graph.size() and j >= 0 and j < graph[0].size() and graph[i][j] != 0);
    }
};

class Solution
{
public:
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    queue<pii> que;
    vector<vector<bool>> vis;
    vector<vi> lev;

    int bfs(vector<vector<int>>& graph)
    {
        int m;

        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;

            que.pop();
            m = lev[i][j];

            for (const auto& k : dir)
            {
                int ni = k.first + i;
                int nj = k.second + j;
                if (valid(ni, nj, graph) and !vis[ni][nj])
                {
                    que.push({ni, nj});
                    vis[ni][nj] = true;
                    lev[ni][nj] = lev[i][j] + 1;
                }
            }
        }
        if (m == 0) return -1;
        return m;
    }
    bool valid(int i, int j, vector<vector<int>>& graph)
    {
        return (i >= 0 and i < graph.size() and j >= 0 and j < graph[0].size());
    }
    int maxDistance(vector<vector<int>>& graph)
    {
        vis.resize(graph.size(), vector<bool>(graph[0].size(), false));
        lev.resize(graph.size(), vi(graph[0].size()));
        for (auto i = 0; i < graph.size(); i++)
        {
            for (auto j = 0; j < graph[0].size(); j++)
            {
                if (graph[i][j] == 0) continue;
                lev[i][j] = 0;
                vis[i][j] = true;
                que.push({i, j});
            }
        }
        if (que.empty()) return -1;
        return bfs(graph);

    }
};

class Solution
{
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    vector<vi> vis;
    vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        vis.resize(grid1.size(), vi(grid1[0].size(), false));
        int m = 0;
        for (auto i = 0; i < grid1.size(); i++)
        {
            for (auto j = 0; j < grid1[0].size(); j++)
            {
                if (vis[i][j] or grid1[i][j] == 0 or grid2[i][j] == 0) continue;
                m +=  bfs(i, j, grid1, grid2);

            }
        }
        return m;
    }


    int bfs(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        queue<pii> que;
        que.push({si, sj});
        vis[si][sj] = true;
        int c = 1;

        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;

            if (grid1[i][j] == 0) c = 0;

            que.pop();

            for (const auto& k : dir)
            {
                int ni = k.first + i;
                int nj = k.second + j;
                if (valid(ni, nj, grid2) and !vis[ni][nj])
                {
                    que.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
        }

        return c;
    }
    bool valid(int i, int j, vector<vector<int>>& grid2)
    {
        return (i >= 0 and i < grid2.size() and j >= 0 and j < grid2[0].size() and grid2[i][j] != 0);
    }
};

class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    unordered_map<Node*, Node*> vis;
public:
    Node* cloneGraph(Node* node)
    {
        if (!node) return nullptr;
        Node* newNode = new Node(node->val);
        vis[node] = newNode;
        for (const auto& i : node->neighbors)
        {
            if (vis.count(i))
                newNode->neighbors.push_back(vis[i]);
            else
                newNode->neighbors.push_back(cloneGraph(i));
        }

        return newNode;
    }
};

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {

    }
};
