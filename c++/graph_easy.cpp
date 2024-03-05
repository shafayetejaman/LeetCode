#include <bits/stdc++.h>

using namespace std;


int main()
{


    return 0;
}

class Solution
{
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    queue<pii> que;
    vector<vector<bool>> vis;

    int bfs(vector<vector<int>>& graph, int si, int sj)
    {
        int c = 0;
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
                else if (!valid(ni, nj, graph)) c++;
            }
        }
        return c;

    }
    bool valid(int i, int j, vector<vector<int>>& graph)
    {
        return (i >= 0 and i < graph.size() and j >= 0 and j < graph[0].size() and graph[i][j] != 0);
    }
    
public:
    int islandPerimeter(vector<vector<int>>& graph)
    {
        vis.resize(graph.size(), vector<bool>(graph[0].size(), false));

        for (auto i = 0; i < graph.size(); i++)
        {
            for (auto j = 0; j < graph[0].size(); j++)
            {
                if (graph[i][j] == 0) continue;

                return bfs(graph, i, j);

            }
        }
        return 0;
    }
};

class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {

        
    }
};