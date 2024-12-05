/*This algorithms is vertex based, choose the minimum weight edge everytime and make sure edges are connected and also check cycle detection using Union find disjoint set*/
#include <bits/stdc++.h>
using namespace std;

int getParent(int i, int parent[])
{
    if (parent[i] == i)
        return i;
    return getParent(parent[i], parent);
}

bool isCycle(int u, int v, int parent[])
{
    int i = getParent(u, parent);
    int j = getParent(v, parent);
    // cout << i << " " << j << "\n";
    if (i != j)
    {
        parent[i] = j;
        return false;
    }
    return true;
}
void prims(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p, map<int, vector<pair<int, int>>> m, int n)
{
    vector<pair<int, pair<int, int>>> tree;
    vector<int> v(n, 0);
    int parent[n + 1];
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    while (!p.empty())
    {
        auto top = p.top();
        if (tree.size() == 0)
        {
            if (!isCycle(top.second.first, top.second.second, parent))
            {
                tree.push_back({top.first, {top.second.first, top.second.second}});
                v[top.second.first] = 1;
                v[top.second.second] = 1;
            }
        }
        else
        {
            int u1 = top.second.first, v1 = top.second.second;
            if ((v[u1] == 1 && v[v1] == 0) || v[u1] == 0 && v[v1] == 1)
            {
                vector<pair<int, int>> adj = m[u1];
                for (int i = 0; i < adj.size(); i++)
                {
                    p.push({adj[i].second, {u1, adj[i].first}});
                }
                adj = m[v1];
                for (int i = 0; i < adj.size(); i++)
                {
                    p.push({adj[i].second, {v1, adj[i].first}});
                }
            }
            if (!isCycle(top.second.first, top.second.second, parent))
            {
                tree.push_back({top.first, {top.second.first, top.second.second}});
                v[top.second.first] = 1;
                v[top.second.second] = 1;
            }
        }
        p.pop();
    }
    int mst = 0;
    for (auto i : tree)
    {
        mst += i.first;
        cout << "Edge: (" << i.second.first << ", " << i.second.second << ")\n";
    }
    cout << "Minimum Spanning Tree of Prims is: " << mst << "\n";
}
int main()
{
    int n, e;
    cin >> n >> e;
    int v[n] = {0};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    map<int, vector<pair<int, int>>> m;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        p.push({w, {u, v}});
        m[u].push_back({v, w});
        m[v].push_back({u, w});
    }
    // while (!p.empty())
    // {
    //     auto top = p.top();
    //     cout << "Weight: " << top.first << ", Edge: (" << top.second.first << ", " << top.second.second << ")\n";
    //     p.pop();
    // }
    prims(p, m, n);
}